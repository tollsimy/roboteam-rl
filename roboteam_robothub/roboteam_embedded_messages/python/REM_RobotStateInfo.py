# AUTOGENERATED. Run generator/main.py to regenerate
"""
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ] [  10  ] [  11  ] [  12  ] [  13  ] [  14  ] [  15  ] [  16  ] [  17  ] [  18  ] [  19  ] [  20  ] [  21  ] [  22  ] [  23  ] [  24  ] [  25  ] [  26  ] [  27  ] [  28  ] [  29  ] [  30  ] [  31  ] [  32  ] [  33  ] [  34  ] [  35  ] [  36  ] [  37  ] [  38  ] [  39  ] [  40  ] [  41  ] [  42  ] [  43  ] [  44  ] [  45  ] [  46  ] [  47  ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toRobotId
-------- ----1--- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toColor
-------- -----1-- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toBC
-------- ------1- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toBS
-------- -------1 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- toPC
-------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromRobotId
-------- -------- ----1--- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromColor
-------- -------- -----1-- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- reserved
-------- -------- ------1- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromBS
-------- -------- -------1 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- fromPC
-------- -------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- remVersion
-------- -------- -------- ----1111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- messageId
-------- -------- -------- -------- 11111111 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- timestamp
-------- -------- -------- -------- -------- -------- -------- 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- payloadSize
-------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- xsensAcc1
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- xsensAcc2
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- xsensYaw
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- rateOfTurn
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- wheelSpeed1
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- wheelSpeed2
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- wheelSpeed3
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- wheelSpeed4
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- dribbleSpeed
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- filteredDribbleSpeed
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- dribblespeedBeforeGotBall
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- bodyXIntegral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- bodyYIntegral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- bodyWIntegral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- -------- -------- bodyYawIntegral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- -------- -------- wheel1Integral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- -------- -------- wheel2Integral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 -------- -------- wheel3Integral
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 11111111 11111111 wheel4Integral
"""

import numpy as np
from . import REM_BaseTypes



class REM_RobotStateInfo:
    header = 0                # integer [0, 255]             Header byte indicating the type of packet
    toRobotId = 0             # integer [0, 15]              Id of the receiving robot
    toColor = 0               # integer [0, 1]               Color of the receiving robot / basestation. Yellow = 0, Blue = 1
    toBC = 0                  # integer [0, 1]               Bit indicating this packet has to be broadcasted to all robots
    toBS = 0                  # integer [0, 1]               Bit indicating this packet is meant for the basestation
    toPC = 0                  # integer [0, 1]               Bit indicating this packet is meant for the PC
    fromRobotId = 0           # integer [0, 15]              Id of the transmitting robot
    fromColor = 0             # integer [0, 1]               Color of the transmitting robot / basestation. Yellow = 0, Blue = 1
    reserved = 0              # integer [0, 1]               reserved
    fromBS = 0                # integer [0, 1]               Bit indicating this packet is coming from the basestation
    fromPC = 0                # integer [0, 1]               Bit indicating this packet is coming from the PC
    remVersion = 0            # integer [0, 15]              Version of roboteam_embedded_messages
    messageId = 0             # integer [0, 15]              messageId. Can be used for aligning packets
    timestamp = 0             # integer [0, 16777215]        Timestamp in milliseconds
    payloadSize = 0           # integer [0, 255]             Size of the payload. At most 255 bytes including the generic_packet_header. Keep the 127 byte SX1280 limit in mind
    xsensAcc1 = 0             # float   [-156.960, 156.960]  xsensAcc1
    xsensAcc2 = 0             # float   [-156.960, 156.960]  xsensAcc2
    xsensYaw = 0              # float   [-50000.000, 50000.000] xsensYaw
    rateOfTurn = 0            # float   [-20.000, 20.000]    rateOfTurn
    wheelSpeed1 = 0           # float   [-1000.000, 1000.000] wheelSpeed1
    wheelSpeed2 = 0           # float   [-1000.000, 1000.000] wheelSpeed2
    wheelSpeed3 = 0           # float   [-1000.000, 1000.000] wheelSpeed3
    wheelSpeed4 = 0           # float   [-1000.000, 1000.000] wheelSpeed4
    dribbleSpeed = 0          # float   [0.000, 5000.000]    dribblerSpeed
    filteredDribbleSpeed = 0  # float   [0.000, 5000.000]    filtered dribblerSpeed
    dribblespeedBeforeGotBall = 0 # float   [0.000, 5000.000]    dribblerSpeed at at the time dribbler thinks it got the ball
    bodyXIntegral = 0         # float   [-5000.000, 5000.000] Integral value from the PID for body_x
    bodyYIntegral = 0         # float   [-5000.000, 5000.000] Integral value from the PID for body_y
    bodyWIntegral = 0         # float   [-5000.000, 5000.000] Integral value from the PID for body_w
    bodyYawIntegral = 0       # float   [-5000.000, 5000.000] Integral value from the PID for body_Yaw
    wheel1Integral = 0        # float   [-5000.000, 5000.000] Integral value from the PID for Wheel_1
    wheel2Integral = 0        # float   [-5000.000, 5000.000] Integral value from the PID for Wheel_2
    wheel3Integral = 0        # float   [-5000.000, 5000.000] Integral value from the PID for Wheel_3
    wheel4Integral = 0        # float   [-5000.000, 5000.000] Integral value from the PID for Wheel_4



# ================================ GETTERS ================================
    @staticmethod
    def get_header(payload):
        return ((payload[0]));

    @staticmethod
    def get_toRobotId(payload):
        return ((payload[1] & 0b11110000) >> 4);

    @staticmethod
    def get_toColor(payload):
        return (payload[1] & 0b00001000) > 0;

    @staticmethod
    def get_toBC(payload):
        return (payload[1] & 0b00000100) > 0;

    @staticmethod
    def get_toBS(payload):
        return (payload[1] & 0b00000010) > 0;

    @staticmethod
    def get_toPC(payload):
        return (payload[1] & 0b00000001) > 0;

    @staticmethod
    def get_fromRobotId(payload):
        return ((payload[2] & 0b11110000) >> 4);

    @staticmethod
    def get_fromColor(payload):
        return (payload[2] & 0b00001000) > 0;

    @staticmethod
    def get_reserved(payload):
        return (payload[2] & 0b00000100) > 0;

    @staticmethod
    def get_fromBS(payload):
        return (payload[2] & 0b00000010) > 0;

    @staticmethod
    def get_fromPC(payload):
        return (payload[2] & 0b00000001) > 0;

    @staticmethod
    def get_remVersion(payload):
        return ((payload[3] & 0b11110000) >> 4);

    @staticmethod
    def get_messageId(payload):
        return ((payload[3] & 0b00001111));

    @staticmethod
    def get_timestamp(payload):
        return ((payload[4]) << 16) | ((payload[5]) << 8) | ((payload[6]));

    @staticmethod
    def get_payloadSize(payload):
        return ((payload[7]));

    @staticmethod
    def get_xsensAcc1(payload):
        _xsensAcc1 = ((payload[8]) << 8) | ((payload[9]));
        return (_xsensAcc1 * 0.0047901121538109) + -156.9600000000000080;

    @staticmethod
    def get_xsensAcc2(payload):
        _xsensAcc2 = ((payload[10]) << 8) | ((payload[11]));
        return (_xsensAcc2 * 0.0047901121538109) + -156.9600000000000080;

    @staticmethod
    def get_xsensYaw(payload):
        _xsensYaw = ((payload[12]) << 24) | ((payload[13]) << 16) | ((payload[14]) << 8) | ((payload[15]));
        return (_xsensYaw * 0.0000232830643708) + -50000.0000000000000000;

    @staticmethod
    def get_rateOfTurn(payload):
        _rateOfTurn = ((payload[16]) << 8) | ((payload[17]));
        return (_rateOfTurn * 0.0006103608758679) + -20.0000000000000000;

    @staticmethod
    def get_wheelSpeed1(payload):
        _wheelSpeed1 = ((payload[18]) << 8) | ((payload[19]));
        return (_wheelSpeed1 * 0.0305180437933928) + -1000.0000000000000000;

    @staticmethod
    def get_wheelSpeed2(payload):
        _wheelSpeed2 = ((payload[20]) << 8) | ((payload[21]));
        return (_wheelSpeed2 * 0.0305180437933928) + -1000.0000000000000000;

    @staticmethod
    def get_wheelSpeed3(payload):
        _wheelSpeed3 = ((payload[22]) << 8) | ((payload[23]));
        return (_wheelSpeed3 * 0.0305180437933928) + -1000.0000000000000000;

    @staticmethod
    def get_wheelSpeed4(payload):
        _wheelSpeed4 = ((payload[24]) << 8) | ((payload[25]));
        return (_wheelSpeed4 * 0.0305180437933928) + -1000.0000000000000000;

    @staticmethod
    def get_dribbleSpeed(payload):
        _dribbleSpeed = ((payload[26]) << 8) | ((payload[27]));
        return (_dribbleSpeed * 0.0762951094834821);

    @staticmethod
    def get_filteredDribbleSpeed(payload):
        _filteredDribbleSpeed = ((payload[28]) << 8) | ((payload[29]));
        return (_filteredDribbleSpeed * 0.0762951094834821);

    @staticmethod
    def get_dribblespeedBeforeGotBall(payload):
        _dribblespeedBeforeGotBall = ((payload[30]) << 8) | ((payload[31]));
        return (_dribblespeedBeforeGotBall * 0.0762951094834821);

    @staticmethod
    def get_bodyXIntegral(payload):
        _bodyXIntegral = ((payload[32]) << 8) | ((payload[33]));
        return (_bodyXIntegral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_bodyYIntegral(payload):
        _bodyYIntegral = ((payload[34]) << 8) | ((payload[35]));
        return (_bodyYIntegral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_bodyWIntegral(payload):
        _bodyWIntegral = ((payload[36]) << 8) | ((payload[37]));
        return (_bodyWIntegral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_bodyYawIntegral(payload):
        _bodyYawIntegral = ((payload[38]) << 8) | ((payload[39]));
        return (_bodyYawIntegral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_wheel1Integral(payload):
        _wheel1Integral = ((payload[40]) << 8) | ((payload[41]));
        return (_wheel1Integral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_wheel2Integral(payload):
        _wheel2Integral = ((payload[42]) << 8) | ((payload[43]));
        return (_wheel2Integral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_wheel3Integral(payload):
        _wheel3Integral = ((payload[44]) << 8) | ((payload[45]));
        return (_wheel3Integral * 0.1525902189669642) + -5000.0000000000000000;

    @staticmethod
    def get_wheel4Integral(payload):
        _wheel4Integral = ((payload[46]) << 8) | ((payload[47]));
        return (_wheel4Integral * 0.1525902189669642) + -5000.0000000000000000;

# ================================ SETTERS ================================
    @staticmethod
    def set_header(payload, header):
        payload[0] = header;

    @staticmethod
    def set_toRobotId(payload, toRobotId):
        payload[1] = ((toRobotId << 4) & 0b11110000) | (payload[1] & 0b00001111);

    @staticmethod
    def set_toColor(payload, toColor):
        payload[1] = ((toColor << 3) & 0b00001000) | (payload[1] & 0b11110111);

    @staticmethod
    def set_toBC(payload, toBC):
        payload[1] = ((toBC << 2) & 0b00000100) | (payload[1] & 0b11111011);

    @staticmethod
    def set_toBS(payload, toBS):
        payload[1] = ((toBS << 1) & 0b00000010) | (payload[1] & 0b11111101);

    @staticmethod
    def set_toPC(payload, toPC):
        payload[1] = (toPC & 0b00000001) | (payload[1] & 0b11111110);

    @staticmethod
    def set_fromRobotId(payload, fromRobotId):
        payload[2] = ((fromRobotId << 4) & 0b11110000) | (payload[2] & 0b00001111);

    @staticmethod
    def set_fromColor(payload, fromColor):
        payload[2] = ((fromColor << 3) & 0b00001000) | (payload[2] & 0b11110111);

    @staticmethod
    def set_reserved(payload, reserved):
        payload[2] = ((reserved << 2) & 0b00000100) | (payload[2] & 0b11111011);

    @staticmethod
    def set_fromBS(payload, fromBS):
        payload[2] = ((fromBS << 1) & 0b00000010) | (payload[2] & 0b11111101);

    @staticmethod
    def set_fromPC(payload, fromPC):
        payload[2] = (fromPC & 0b00000001) | (payload[2] & 0b11111110);

    @staticmethod
    def set_remVersion(payload, remVersion):
        payload[3] = ((remVersion << 4) & 0b11110000) | (payload[3] & 0b00001111);

    @staticmethod
    def set_messageId(payload, messageId):
        payload[3] = (messageId & 0b00001111) | (payload[3] & 0b11110000);

    @staticmethod
    def set_timestamp(payload, timestamp):
        payload[4] = (timestamp >> 16);
        payload[5] = (timestamp >> 8);
        payload[6] = timestamp;

    @staticmethod
    def set_payloadSize(payload, payloadSize):
        payload[7] = payloadSize;

    @staticmethod
    def set_xsensAcc1(payload, xsensAcc1):
        _xsensAcc1 = int((xsensAcc1 +156.9600000000000080) / 0.0047901121538109);
        payload[8] = (_xsensAcc1 >> 8);
        payload[9] = _xsensAcc1;

    @staticmethod
    def set_xsensAcc2(payload, xsensAcc2):
        _xsensAcc2 = int((xsensAcc2 +156.9600000000000080) / 0.0047901121538109);
        payload[10] = (_xsensAcc2 >> 8);
        payload[11] = _xsensAcc2;

    @staticmethod
    def set_xsensYaw(payload, xsensYaw):
        _xsensYaw = int((xsensYaw +50000.0000000000000000) / 0.0000232830643708);
        payload[12] = (_xsensYaw >> 24);
        payload[13] = (_xsensYaw >> 16);
        payload[14] = (_xsensYaw >> 8);
        payload[15] = _xsensYaw;

    @staticmethod
    def set_rateOfTurn(payload, rateOfTurn):
        _rateOfTurn = int((rateOfTurn +20.0000000000000000) / 0.0006103608758679);
        payload[16] = (_rateOfTurn >> 8);
        payload[17] = _rateOfTurn;

    @staticmethod
    def set_wheelSpeed1(payload, wheelSpeed1):
        _wheelSpeed1 = int((wheelSpeed1 +1000.0000000000000000) / 0.0305180437933928);
        payload[18] = (_wheelSpeed1 >> 8);
        payload[19] = _wheelSpeed1;

    @staticmethod
    def set_wheelSpeed2(payload, wheelSpeed2):
        _wheelSpeed2 = int((wheelSpeed2 +1000.0000000000000000) / 0.0305180437933928);
        payload[20] = (_wheelSpeed2 >> 8);
        payload[21] = _wheelSpeed2;

    @staticmethod
    def set_wheelSpeed3(payload, wheelSpeed3):
        _wheelSpeed3 = int((wheelSpeed3 +1000.0000000000000000) / 0.0305180437933928);
        payload[22] = (_wheelSpeed3 >> 8);
        payload[23] = _wheelSpeed3;

    @staticmethod
    def set_wheelSpeed4(payload, wheelSpeed4):
        _wheelSpeed4 = int((wheelSpeed4 +1000.0000000000000000) / 0.0305180437933928);
        payload[24] = (_wheelSpeed4 >> 8);
        payload[25] = _wheelSpeed4;

    @staticmethod
    def set_dribbleSpeed(payload, dribbleSpeed):
        _dribbleSpeed = int(dribbleSpeed / 0.0762951094834821);
        payload[26] = (_dribbleSpeed >> 8);
        payload[27] = _dribbleSpeed;

    @staticmethod
    def set_filteredDribbleSpeed(payload, filteredDribbleSpeed):
        _filteredDribbleSpeed = int(filteredDribbleSpeed / 0.0762951094834821);
        payload[28] = (_filteredDribbleSpeed >> 8);
        payload[29] = _filteredDribbleSpeed;

    @staticmethod
    def set_dribblespeedBeforeGotBall(payload, dribblespeedBeforeGotBall):
        _dribblespeedBeforeGotBall = int(dribblespeedBeforeGotBall / 0.0762951094834821);
        payload[30] = (_dribblespeedBeforeGotBall >> 8);
        payload[31] = _dribblespeedBeforeGotBall;

    @staticmethod
    def set_bodyXIntegral(payload, bodyXIntegral):
        _bodyXIntegral = int((bodyXIntegral +5000.0000000000000000) / 0.1525902189669642);
        payload[32] = (_bodyXIntegral >> 8);
        payload[33] = _bodyXIntegral;

    @staticmethod
    def set_bodyYIntegral(payload, bodyYIntegral):
        _bodyYIntegral = int((bodyYIntegral +5000.0000000000000000) / 0.1525902189669642);
        payload[34] = (_bodyYIntegral >> 8);
        payload[35] = _bodyYIntegral;

    @staticmethod
    def set_bodyWIntegral(payload, bodyWIntegral):
        _bodyWIntegral = int((bodyWIntegral +5000.0000000000000000) / 0.1525902189669642);
        payload[36] = (_bodyWIntegral >> 8);
        payload[37] = _bodyWIntegral;

    @staticmethod
    def set_bodyYawIntegral(payload, bodyYawIntegral):
        _bodyYawIntegral = int((bodyYawIntegral +5000.0000000000000000) / 0.1525902189669642);
        payload[38] = (_bodyYawIntegral >> 8);
        payload[39] = _bodyYawIntegral;

    @staticmethod
    def set_wheel1Integral(payload, wheel1Integral):
        _wheel1Integral = int((wheel1Integral +5000.0000000000000000) / 0.1525902189669642);
        payload[40] = (_wheel1Integral >> 8);
        payload[41] = _wheel1Integral;

    @staticmethod
    def set_wheel2Integral(payload, wheel2Integral):
        _wheel2Integral = int((wheel2Integral +5000.0000000000000000) / 0.1525902189669642);
        payload[42] = (_wheel2Integral >> 8);
        payload[43] = _wheel2Integral;

    @staticmethod
    def set_wheel3Integral(payload, wheel3Integral):
        _wheel3Integral = int((wheel3Integral +5000.0000000000000000) / 0.1525902189669642);
        payload[44] = (_wheel3Integral >> 8);
        payload[45] = _wheel3Integral;

    @staticmethod
    def set_wheel4Integral(payload, wheel4Integral):
        _wheel4Integral = int((wheel4Integral +5000.0000000000000000) / 0.1525902189669642);
        payload[46] = (_wheel4Integral >> 8);
        payload[47] = _wheel4Integral;

# ================================ ENCODE ================================
    def encode(self):
        payload = np.zeros(REM_BaseTypes.REM_PACKET_SIZE_REM_ROBOT_STATE_INFO, dtype=np.uint8)
        REM_RobotStateInfo.set_header              (payload, self.header)
        REM_RobotStateInfo.set_toRobotId           (payload, self.toRobotId)
        REM_RobotStateInfo.set_toColor             (payload, self.toColor)
        REM_RobotStateInfo.set_toBC                (payload, self.toBC)
        REM_RobotStateInfo.set_toBS                (payload, self.toBS)
        REM_RobotStateInfo.set_toPC                (payload, self.toPC)
        REM_RobotStateInfo.set_fromRobotId         (payload, self.fromRobotId)
        REM_RobotStateInfo.set_fromColor           (payload, self.fromColor)
        REM_RobotStateInfo.set_reserved            (payload, self.reserved)
        REM_RobotStateInfo.set_fromBS              (payload, self.fromBS)
        REM_RobotStateInfo.set_fromPC              (payload, self.fromPC)
        REM_RobotStateInfo.set_remVersion          (payload, self.remVersion)
        REM_RobotStateInfo.set_messageId           (payload, self.messageId)
        REM_RobotStateInfo.set_timestamp           (payload, self.timestamp)
        REM_RobotStateInfo.set_payloadSize         (payload, self.payloadSize)
        REM_RobotStateInfo.set_xsensAcc1           (payload, self.xsensAcc1)
        REM_RobotStateInfo.set_xsensAcc2           (payload, self.xsensAcc2)
        REM_RobotStateInfo.set_xsensYaw            (payload, self.xsensYaw)
        REM_RobotStateInfo.set_rateOfTurn          (payload, self.rateOfTurn)
        REM_RobotStateInfo.set_wheelSpeed1         (payload, self.wheelSpeed1)
        REM_RobotStateInfo.set_wheelSpeed2         (payload, self.wheelSpeed2)
        REM_RobotStateInfo.set_wheelSpeed3         (payload, self.wheelSpeed3)
        REM_RobotStateInfo.set_wheelSpeed4         (payload, self.wheelSpeed4)
        REM_RobotStateInfo.set_dribbleSpeed        (payload, self.dribbleSpeed)
        REM_RobotStateInfo.set_filteredDribbleSpeed(payload, self.filteredDribbleSpeed)
        REM_RobotStateInfo.set_dribblespeedBeforeGotBall(payload, self.dribblespeedBeforeGotBall)
        REM_RobotStateInfo.set_bodyXIntegral       (payload, self.bodyXIntegral)
        REM_RobotStateInfo.set_bodyYIntegral       (payload, self.bodyYIntegral)
        REM_RobotStateInfo.set_bodyWIntegral       (payload, self.bodyWIntegral)
        REM_RobotStateInfo.set_bodyYawIntegral     (payload, self.bodyYawIntegral)
        REM_RobotStateInfo.set_wheel1Integral      (payload, self.wheel1Integral)
        REM_RobotStateInfo.set_wheel2Integral      (payload, self.wheel2Integral)
        REM_RobotStateInfo.set_wheel3Integral      (payload, self.wheel3Integral)
        REM_RobotStateInfo.set_wheel4Integral      (payload, self.wheel4Integral)
        return payload


# ================================ DECODE ================================
    def decode(self, payload):
        self.header           = REM_RobotStateInfo.get_header(payload)
        self.toRobotId        = REM_RobotStateInfo.get_toRobotId(payload)
        self.toColor          = REM_RobotStateInfo.get_toColor(payload)
        self.toBC             = REM_RobotStateInfo.get_toBC(payload)
        self.toBS             = REM_RobotStateInfo.get_toBS(payload)
        self.toPC             = REM_RobotStateInfo.get_toPC(payload)
        self.fromRobotId      = REM_RobotStateInfo.get_fromRobotId(payload)
        self.fromColor        = REM_RobotStateInfo.get_fromColor(payload)
        self.reserved         = REM_RobotStateInfo.get_reserved(payload)
        self.fromBS           = REM_RobotStateInfo.get_fromBS(payload)
        self.fromPC           = REM_RobotStateInfo.get_fromPC(payload)
        self.remVersion       = REM_RobotStateInfo.get_remVersion(payload)
        self.messageId        = REM_RobotStateInfo.get_messageId(payload)
        self.timestamp        = REM_RobotStateInfo.get_timestamp(payload)
        self.payloadSize      = REM_RobotStateInfo.get_payloadSize(payload)
        self.xsensAcc1        = REM_RobotStateInfo.get_xsensAcc1(payload)
        self.xsensAcc2        = REM_RobotStateInfo.get_xsensAcc2(payload)
        self.xsensYaw         = REM_RobotStateInfo.get_xsensYaw(payload)
        self.rateOfTurn       = REM_RobotStateInfo.get_rateOfTurn(payload)
        self.wheelSpeed1      = REM_RobotStateInfo.get_wheelSpeed1(payload)
        self.wheelSpeed2      = REM_RobotStateInfo.get_wheelSpeed2(payload)
        self.wheelSpeed3      = REM_RobotStateInfo.get_wheelSpeed3(payload)
        self.wheelSpeed4      = REM_RobotStateInfo.get_wheelSpeed4(payload)
        self.dribbleSpeed     = REM_RobotStateInfo.get_dribbleSpeed(payload)
        self.filteredDribbleSpeed= REM_RobotStateInfo.get_filteredDribbleSpeed(payload)
        self.dribblespeedBeforeGotBall= REM_RobotStateInfo.get_dribblespeedBeforeGotBall(payload)
        self.bodyXIntegral    = REM_RobotStateInfo.get_bodyXIntegral(payload)
        self.bodyYIntegral    = REM_RobotStateInfo.get_bodyYIntegral(payload)
        self.bodyWIntegral    = REM_RobotStateInfo.get_bodyWIntegral(payload)
        self.bodyYawIntegral  = REM_RobotStateInfo.get_bodyYawIntegral(payload)
        self.wheel1Integral   = REM_RobotStateInfo.get_wheel1Integral(payload)
        self.wheel2Integral   = REM_RobotStateInfo.get_wheel2Integral(payload)
        self.wheel3Integral   = REM_RobotStateInfo.get_wheel3Integral(payload)
        self.wheel4Integral   = REM_RobotStateInfo.get_wheel4Integral(payload)


    def print_bit_string(self):
        payload = self.encode()
        for i in range(len(payload)):
            print(format(payload[i], '08b'), end=" ")
        print()
