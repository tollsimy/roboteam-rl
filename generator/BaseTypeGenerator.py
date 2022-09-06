import os
import math
from packets import packets
from datetime import datetime


# REM_RobotCommand => REM_ROBOT_COMMAND
def CamelCaseToUpper(word):
	# Find all indices where a lowercase letter is followed by an uppercase letter
	indices = [ i for i in range(1, len(word)) if word[i-1].islower() and word[i].isupper() ]
	# Insert a _ at all of those indices
	for i in reversed(indices):	word = word[:i] + "_" +  word[i:]
	# Uppercase word
	word = word.upper()

	return word



class BaseTypeGenerator:

	def generate(self, packets, version):

		codewords = ['00100001', '00100010', '00100100', '00100111', '00101000', '00101011', '00101101', '00101110', '00110000', '00110011', '00110101', '00110110', '00111001', '00111010', '00111100', '00111111', '01000001', '01000010', '01000100', '01000111', '01001000', '01001011', '01001101', '01001110', '01010000', '01010011', '01010101', '01010110', '01011001', '01011010', '01011100', '01011111', '01100000', '01100011', '01100101', '01100110', '01101001', '01101010', '01101100', '01101111', '01110001', '01110010', '01110100', '01110111', '01111000', '01111011', '01111101', '01111110', '10000001', '10000010', '10000100', '10000111', '10001000', '10001011', '10001101', '10001110', '10010000', '10010011', '10010101', '10010110', '10011001', '10011010', '10011100', '10011111', '10100000', '10100011', '10100101', '10100110', '10101001', '10101010', '10101100', '10101111', '10110001', '10110010', '10110100', '10110111', '10111000', '10111011', '10111101', '10111110', '11000000', '11000011', '11000101', '11000110', '11001001', '11001010', '11001100', '11001111', '11010001', '11010010', '11010100', '11010111', '11011000', '11011011', '11011101', '11011110', '11100001', '11100010', '11100100', '11100111', '11101000', '11101011', '11101101', '11101110', '11110000', '11110011', '11110101', '11110110', '11111001', '11111010', '11111100']

		if len(codewords) < len(packets.keys()):
			print("[Error] More packets than codewords. Add more codewords. Remove packets! DO SOMETHING!!!")
			exit()

		timestamp = datetime.now()
		timestamp_string = timestamp.strftime("%B %d %Y, %H:%M:%S")
		c = self.comment()
		
		file_string = ""

		file_string += f"{c} AUTOGENERATED. Run generator/main.py to regenerate\n"
		# file_string += f"{c} Generated on %s\n\n" % timestamp.strftime("%B %d %Y, %H:%M:%S")

		file_string += f"{c} Warning : Check the unicode table before assigning a byte, to make sure that the byte isn't used for anything special : https://unicode-table.com/\n"
		file_string += f"{c} For example, don't use the following bytes\n"
		file_string += f"{c} 0b00000000 : The null-terminator, used to signal the end of strings / arrays / etc.\n"
		file_string += f"{c} 0b00001010 : The byte for newline, used for line termination.\n"
		file_string += f"\n"

		file_string += self.to_begin(packets) + "\n"

		file_string += self.to_constant("LOCAL_REM_VERSION", version) + "\n\n"

		type_to_size = []

		for iPacket, packet_name in enumerate(packets.keys()):
			variables = packets[packet_name]
			total_bits = sum([variable[1] for variable in variables])
			total_bytes = math.ceil(total_bits / 8)
			PACKET_NAME = CamelCaseToUpper(packet_name)

			VARIABLE_NAME_TYPE = f"PACKET_TYPE_{PACKET_NAME}".ljust(60)
			file_string += f"{self.to_constant(VARIABLE_NAME_TYPE, codewords[iPacket])} {c} {str(int(codewords[iPacket], 2))} \n"

			VARIABLE_NAME_SIZE = f"PACKET_SIZE_{PACKET_NAME}".ljust(60)
			file_string += self.to_constant(VARIABLE_NAME_SIZE, total_bytes) + "\n"

			type_to_size.append([VARIABLE_NAME_TYPE, VARIABLE_NAME_SIZE])

			for variable, n_bits, _range, _ in variables:
				range_min, range_max = 0, 2**n_bits-1
				if _range is not None: range_min, range_max = _range

				VARIABLE_NAME = CamelCaseToUpper(variable)
				file_string += self.to_constant(f"PACKET_RANGE_{PACKET_NAME}_{VARIABLE_NAME}_MIN".ljust(60), f"{range_min:.16f}".rstrip('0')) + "\n"
				file_string += self.to_constant(f"PACKET_RANGE_{PACKET_NAME}_{VARIABLE_NAME}_MAX".ljust(60), f"{range_max:.16f}".rstrip('0')) + "\n"
				file_string += self.to_constant(f"PACKET_RANGE_{PACKET_NAME}_{VARIABLE_NAME}_N_BITS".ljust(60), f"{n_bits}" + "\n")

			file_string += "\n"

		file_string += self.to_type_size_mapping(type_to_size)
		file_string += self.to_type_obj_mapping(packets.keys())
		file_string += "\n"

		file_string += self.to_end()
		
		return file_string

	def begin_block_comment(self):
		raise NotImplementedError()
	def end_block_comment(self):
		raise NotImplementedError()
	def comment(self):
		raise NotImplementedError()

	def to_begin(self, packets):
		return ""
	def to_end(self):
		return ""

	def to_constant(self, variable_name, value):
		raise NotImplementedError()

	def to_type_size_mapping(self, type_to_size):
		raise NotImplementedError()
	
	def to_type_obj_mapping(self, types):
		return ""

class C_BaseTypeGenerator(BaseTypeGenerator):
	def begin_block_comment(self):
		return "/*"
	def end_block_comment(self):
		return "*/"
	def comment(self):
		return "//"

	def to_begin(self, packets):
		begin_string = ""
		begin_string += "#ifndef __BASETYPES_H\n"
		begin_string += "#define __BASETYPES_H\n"
		begin_string += "\n"
		begin_string += "#include <stdint.h>\n"
		begin_string += "\n"
		return begin_string

	def to_end(self):
		return "#endif /*__BASETYPES_H*/"

	def to_constant(self, variable_name, value):
		return f"#define {variable_name} {value}"

	def to_type_size_mapping(self, type_to_size):
		function = """static uint8_t PACKET_TYPE_TO_SIZE(uint8_t type){\n"""
		for _type, size in type_to_size:
			function += f"    if(type == {_type}) return {size};\n"
		function += """    return 0;\n"""
		function += """}\n"""
		return function

class Python_BaseTypeGenerator(BaseTypeGenerator):
	def begin_block_comment(self):
		return '"""'
	def end_block_comment(self):
		return '"""'
	def comment(self):
		return "#"

	def to_constant(self, variable_name, value):
		return f"{variable_name} = {value}"

	def to_begin(self, types):
		import_calls = ""
		for packet_name in packets.keys():
			import_calls += f"from .{packet_name.ljust(40)} import {packet_name}\n"
		return import_calls

	def to_type_size_mapping(self, type_to_size):
		function = """def PACKET_TYPE_TO_SIZE(type):\n"""
		for _type, size in type_to_size:
			function += f"    if type == {_type}: return {size}\n"
		function += """    return 0\n"""
		function += """\n"""
		return function

	def to_type_obj_mapping(self, types):
		function = """def PACKET_TYPE_TO_OBJ(type):\n"""
		for _type in types:
			function += f"    if type == PACKET_TYPE_{CamelCaseToUpper(_type).ljust(40)}: return {_type}\n"
		return function


if __name__ == "__main__":
	print("BaseTypesGenerator.py")

	gc = C_BaseTypeGenerator()
	gp = Python_BaseTypeGenerator()

	print("\n")
	# gp.generate(packets, 0)
	print(gp.generate(packets, 0))
	# gc.generate(packets, 0)

	# print("\n")
	# print(gp.generate(packets))
