# AUTOGENERATED. Run generator/main.py to regenerate
# Warning : Check the unicode table before assigning a byte, to make sure that the byte isn't used for anything special : https://unicode-table.com/
# For example, don't use the following bytes
# 0b00000000 : The null-terminator, used to signal the end of strings / arrays / etc.
# 0b00001010 : The byte for newline, used for line termination.

LOCAL_REM_VERSION = 8

PACKET_TYPE_REM_ROBOT_COMMAND                                = 0b00001111 # 15 
PACKET_SIZE_REM_ROBOT_COMMAND                                = 12
PACKET_RANGE_REM_ROBOT_COMMAND_RHO_MIN                       = 0.
PACKET_RANGE_REM_ROBOT_COMMAND_RHO_MAX                       = 8.
PACKET_RANGE_REM_ROBOT_COMMAND_RHO_N_BITS                    = 16
PACKET_RANGE_REM_ROBOT_COMMAND_THETA_MIN                     = -3.1415926535897931
PACKET_RANGE_REM_ROBOT_COMMAND_THETA_MAX                     = 3.1415926535897931
PACKET_RANGE_REM_ROBOT_COMMAND_THETA_N_BITS                  = 16
PACKET_RANGE_REM_ROBOT_COMMAND_ANGLE_MIN                     = -3.1415926535897931
PACKET_RANGE_REM_ROBOT_COMMAND_ANGLE_MAX                     = 3.1415926535897931
PACKET_RANGE_REM_ROBOT_COMMAND_ANGLE_N_BITS                  = 16
PACKET_RANGE_REM_ROBOT_COMMAND_CAMERA_ANGLE_MIN              = -3.1415926535897931
PACKET_RANGE_REM_ROBOT_COMMAND_CAMERA_ANGLE_MAX              = 3.1415926535897931
PACKET_RANGE_REM_ROBOT_COMMAND_CAMERA_ANGLE_N_BITS           = 16
PACKET_RANGE_REM_ROBOT_COMMAND_DRIBBLER_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_COMMAND_DRIBBLER_MAX                  = 1.
PACKET_RANGE_REM_ROBOT_COMMAND_DRIBBLER_N_BITS               = 3
PACKET_RANGE_REM_ROBOT_COMMAND_KICK_CHIP_POWER_MIN           = 0.
PACKET_RANGE_REM_ROBOT_COMMAND_KICK_CHIP_POWER_MAX           = 6.5
PACKET_RANGE_REM_ROBOT_COMMAND_KICK_CHIP_POWER_N_BITS        = 3

PACKET_TYPE_REM_ROBOT_FEEDBACK                               = 0b00110011 # 51 
PACKET_SIZE_REM_ROBOT_FEEDBACK                               = 12
PACKET_RANGE_REM_ROBOT_FEEDBACK_BALL_POS_MIN                 = -0.5
PACKET_RANGE_REM_ROBOT_FEEDBACK_BALL_POS_MAX                 = 0.5
PACKET_RANGE_REM_ROBOT_FEEDBACK_BALL_POS_N_BITS              = 4
PACKET_RANGE_REM_ROBOT_FEEDBACK_RHO_MIN                      = 0.
PACKET_RANGE_REM_ROBOT_FEEDBACK_RHO_MAX                      = 8.
PACKET_RANGE_REM_ROBOT_FEEDBACK_RHO_N_BITS                   = 16
PACKET_RANGE_REM_ROBOT_FEEDBACK_THETA_MIN                    = -3.1415926535897931
PACKET_RANGE_REM_ROBOT_FEEDBACK_THETA_MAX                    = 3.1415926535897931
PACKET_RANGE_REM_ROBOT_FEEDBACK_THETA_N_BITS                 = 16
PACKET_RANGE_REM_ROBOT_FEEDBACK_ANGLE_MIN                    = -3.1415926535897931
PACKET_RANGE_REM_ROBOT_FEEDBACK_ANGLE_MAX                    = 3.1415926535897931
PACKET_RANGE_REM_ROBOT_FEEDBACK_ANGLE_N_BITS                 = 16

PACKET_TYPE_REM_ROBOT_STATE_INFO                             = 0b00111100 # 60 
PACKET_SIZE_REM_ROBOT_STATE_INFO                             = 35
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_ACC1_MIN             = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_ACC1_MAX             = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_ACC1_N_BITS          = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_ACC2_MIN             = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_ACC2_MAX             = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_ACC2_N_BITS          = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_YAW_MIN              = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_YAW_MAX              = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_XSENS_YAW_N_BITS           = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_RATE_OF_TURN_MIN           = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_RATE_OF_TURN_MAX           = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_RATE_OF_TURN_N_BITS        = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED1_MIN           = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED1_MAX           = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED1_N_BITS        = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED2_MIN           = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED2_MAX           = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED2_N_BITS        = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED3_MIN           = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED3_MAX           = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED3_N_BITS        = 32
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED4_MIN           = -50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED4_MAX           = 50000.
PACKET_RANGE_REM_ROBOT_STATE_INFO_WHEEL_SPEED4_N_BITS        = 32

PACKET_TYPE_REM_ROBOT_BUZZER                                 = 0b01010101 # 85 
PACKET_SIZE_REM_ROBOT_BUZZER                                 = 6
PACKET_RANGE_REM_ROBOT_BUZZER_DURATION_MIN                   = 0.
PACKET_RANGE_REM_ROBOT_BUZZER_DURATION_MAX                   = 5.
PACKET_RANGE_REM_ROBOT_BUZZER_DURATION_N_BITS                = 16

PACKET_TYPE_REM_BASESTATION_LOG                              = 0b01011010 # 90 
PACKET_SIZE_REM_BASESTATION_LOG                              = 1

PACKET_TYPE_REM_ROBOT_LOG                                    = 0b01100110 # 102 
PACKET_SIZE_REM_ROBOT_LOG                                    = 3

PACKET_TYPE_REM_BASESTATION_GET_CONFIGURATION                = 0b01101001 # 105 
PACKET_SIZE_REM_BASESTATION_GET_CONFIGURATION                = 1

PACKET_TYPE_REM_BASESTATION_CONFIGURATION                    = 0b10010110 # 150 
PACKET_SIZE_REM_BASESTATION_CONFIGURATION                    = 2

PACKET_TYPE_REM_BASESTATION_SET_CONFIGURATION                = 0b10011001 # 153 
PACKET_SIZE_REM_BASESTATION_SET_CONFIGURATION                = 2

PACKET_TYPE_REM_ROBOT_GET_PIDGAINS                           = 0b10100101 # 165 
PACKET_SIZE_REM_ROBOT_GET_PIDGAINS                           = 2

PACKET_TYPE_REM_ROBOT_PIDGAINS                               = 0b10101010 # 170 
PACKET_SIZE_REM_ROBOT_PIDGAINS                               = 26
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_X_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_X_MAX                  = 40.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_X_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_X_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_X_MAX                  = 20.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_X_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_X_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_X_MAX                  = 10.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_X_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_Y_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_Y_MAX                  = 40.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_Y_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_Y_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_Y_MAX                  = 20.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_Y_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_Y_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_Y_MAX                  = 10.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_Y_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_YAW_MIN                = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_YAW_MAX                = 40.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PBODY_YAW_N_BITS             = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_YAW_MIN                = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_YAW_MAX                = 20.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IBODY_YAW_N_BITS             = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_YAW_MIN                = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_YAW_MAX                = 10.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DBODY_YAW_N_BITS             = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_PWHEELS_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PWHEELS_MAX                  = 40.
PACKET_RANGE_REM_ROBOT_PIDGAINS_PWHEELS_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_IWHEELS_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IWHEELS_MAX                  = 20.
PACKET_RANGE_REM_ROBOT_PIDGAINS_IWHEELS_N_BITS               = 16
PACKET_RANGE_REM_ROBOT_PIDGAINS_DWHEELS_MIN                  = 0.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DWHEELS_MAX                  = 10.
PACKET_RANGE_REM_ROBOT_PIDGAINS_DWHEELS_N_BITS               = 16

PACKET_TYPE_REM_SX1280FILLER                                 = 0b11000011 # 195 
PACKET_SIZE_REM_SX1280FILLER                                 = 6

def PACKET_TYPE_TO_SIZE(type):
    if type == PACKET_TYPE_REM_ROBOT_COMMAND                               : return PACKET_SIZE_REM_ROBOT_COMMAND                               
    if type == PACKET_TYPE_REM_ROBOT_FEEDBACK                              : return PACKET_SIZE_REM_ROBOT_FEEDBACK                              
    if type == PACKET_TYPE_REM_ROBOT_STATE_INFO                            : return PACKET_SIZE_REM_ROBOT_STATE_INFO                            
    if type == PACKET_TYPE_REM_ROBOT_BUZZER                                : return PACKET_SIZE_REM_ROBOT_BUZZER                                
    if type == PACKET_TYPE_REM_BASESTATION_LOG                             : return PACKET_SIZE_REM_BASESTATION_LOG                             
    if type == PACKET_TYPE_REM_ROBOT_LOG                                   : return PACKET_SIZE_REM_ROBOT_LOG                                   
    if type == PACKET_TYPE_REM_BASESTATION_GET_CONFIGURATION               : return PACKET_SIZE_REM_BASESTATION_GET_CONFIGURATION               
    if type == PACKET_TYPE_REM_BASESTATION_CONFIGURATION                   : return PACKET_SIZE_REM_BASESTATION_CONFIGURATION                   
    if type == PACKET_TYPE_REM_BASESTATION_SET_CONFIGURATION               : return PACKET_SIZE_REM_BASESTATION_SET_CONFIGURATION               
    if type == PACKET_TYPE_REM_ROBOT_GET_PIDGAINS                          : return PACKET_SIZE_REM_ROBOT_GET_PIDGAINS                          
    if type == PACKET_TYPE_REM_ROBOT_PIDGAINS                              : return PACKET_SIZE_REM_ROBOT_PIDGAINS                              
    if type == PACKET_TYPE_REM_SX1280FILLER                                : return PACKET_SIZE_REM_SX1280FILLER                                
    return 0


