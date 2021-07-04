# AUTOGENERATED. Run generator/main.py to regenerate
# Generated on July 04 2021, 22:50:02

"""
[  0   ] [  1   ] [  2   ] [  3   ] [  4   ] [  5   ] [  6   ] [  7   ] [  8   ] [  9   ] [  10  ]
11111111 -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- header
-------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- -------- id
-------- ----1111 -------- -------- -------- -------- -------- -------- -------- -------- -------- messageId
-------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- -------- batteryLevel
-------- -------- ----1--- -------- -------- -------- -------- -------- -------- -------- -------- XsensCalibrated
-------- -------- -----1-- -------- -------- -------- -------- -------- -------- -------- -------- ballSensorWorking
-------- -------- ------1- -------- -------- -------- -------- -------- -------- -------- -------- hasBall
-------- -------- -------1 -------- -------- -------- -------- -------- -------- -------- -------- capacitorCharged
-------- -------- -------- 1111---- -------- -------- -------- -------- -------- -------- -------- ballPos
-------- -------- -------- ----1111 11111111 1111---- -------- -------- -------- -------- -------- rho
-------- -------- -------- -------- -------- ----1111 11111111 1111---- -------- -------- -------- theta
-------- -------- -------- -------- -------- -------- -------- ----1111 11111111 1111---- -------- angle
-------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 -------- wheelLocked
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- 1111---- wheelBraking
-------- -------- -------- -------- -------- -------- -------- -------- -------- -------- ----1111 rssi
"""




class RobotFeedback:
    header = 0                # Header byte indicating the type of packet
    id = 0                    # Id of the robot 
    messageId = 0             # Id of the message
    batteryLevel = 0          # The voltage level of the battery
    XsensCalibrated = 0       # Indicates if the XSens IMU is calibrated
    ballSensorWorking = 0     # Indicates if the ballsensor is working
    hasBall = 0               # Indicates if the ball is somewhere in front of the ballsensor
    capacitorCharged = 0      # Indicates if the capacitor for kicking and chipping is charged
    ballPos = 0               # Indicates where in front of the ballsensor the ball is
    rho = 0                   # The estimated magnitude of movement (m/s)
    theta = 0                 # The estimated direction of movement (rad)
    angle = 0                 # The estimated angle (rad)
    wheelLocked = 0           # Indicates if a wheel is locked. One bit per wheel
    wheelBraking = 0          # Indicates if a wheel is slipping. One bit per wheel
    rssi = 0                  # Signal strength of the last packet received by the robot



# ================================ GETTERS ================================
    @staticmethod
    get_header(payload):
        return ((payload[0]));

    @staticmethod
    get_id(payload):
        return ((payload[1] & 0b11110000) >> 4);

    @staticmethod
    get_messageId(payload):
        return ((payload[1] & 0b00001111));

    @staticmethod
    get_batteryLevel(payload):
        return ((payload[2] & 0b11110000) >> 4);

    @staticmethod
    get_XsensCalibrated(payload):
        return (payload[2] & 0b00001000) > 0
    @staticmethod
    get_ballSensorWorking(payload):
        return (payload[2] & 0b00000100) > 0
    @staticmethod
    get_hasBall(payload):
        return (payload[2] & 0b00000010) > 0
    @staticmethod
    get_capacitorCharged(payload):
        return (payload[2] & 0b00000001) > 0
    @staticmethod
    get_ballPos(payload):
        _ballPos = ((payload[3] & 0b11110000) >> 4);
        return (_ballPos * 0.0625000000000000) + -0.5000000000000000;

    @staticmethod
    get_rho(payload):
        _rho = ((payload[3] & 0b00001111) << 12) | ((payload[4]) << 4) | ((payload[5] & 0b11110000) >> 4);
        return (_rho * 0.0001220703125000) + 0.0000000000000000;

    @staticmethod
    get_theta(payload):
        _theta = ((payload[5] & 0b00001111) << 12) | ((payload[6]) << 4) | ((payload[7] & 0b11110000) >> 4);
        return (_theta * 0.0000958737992429) + -3.1415926535897931;

    @staticmethod
    get_angle(payload):
        _angle = ((payload[7] & 0b00001111) << 12) | ((payload[8]) << 4) | ((payload[9] & 0b11110000) >> 4);
        return (_angle * 0.0000958737992429) + -3.1415926535897931;

    @staticmethod
    get_wheelLocked(payload):
        return ((payload[9] & 0b00001111));

    @staticmethod
    get_wheelBraking(payload):
        return ((payload[10] & 0b11110000) >> 4);

    @staticmethod
    get_rssi(payload):
        return ((payload[10] & 0b00001111));

# ================================ SETTERS ================================
    @staticmethod
    set_header(payload, header):
        payload[0] = header;

    @staticmethod
    set_id(payload, id):
        payload[1] = ((id << 4) & 0b11110000) | (payload[1] & 0b00001111);

    @staticmethod
    set_messageId(payload, messageId):
        payload[1] = (messageId & 0b00001111) | (payload[1] & 0b11110000);

    @staticmethod
    set_batteryLevel(payload, batteryLevel):
        payload[2] = ((batteryLevel << 4) & 0b11110000) | (payload[2] & 0b00001111);

    @staticmethod
    set_XsensCalibrated(payload, XsensCalibrated):
        payload[2] = ((XsensCalibrated << 3) & 0b00001000) | (payload[2] & 0b11110111);

    @staticmethod
    set_ballSensorWorking(payload, ballSensorWorking):
        payload[2] = ((ballSensorWorking << 2) & 0b00000100) | (payload[2] & 0b11111011);

    @staticmethod
    set_hasBall(payload, hasBall):
        payload[2] = ((hasBall << 1) & 0b00000010) | (payload[2] & 0b11111101);

    @staticmethod
    set_capacitorCharged(payload, capacitorCharged):
        payload[2] = (capacitorCharged & 0b00000001) | (payload[2] & 0b11111110);

    @staticmethod
    set_ballPos(payload, ballPos):
        _ballPos = int((ballPos +0.5000000000000000) / 0.0625000000000000)
        payload[3] = ((_ballPos << 4) & 0b11110000) | (payload[3] & 0b00001111);

    @staticmethod
    set_rho(payload, rho):
        _rho = int(rho / 0.0001220703125000)
        payload[3] = ((_rho >> 12) & 0b00001111) | (payload[3] & 0b11110000);
        payload[4] = (_rho >> 8);
        payload[5] = ((_rho >> 8) & 0b11110000) | (payload[5] & 0b00001111);

    @staticmethod
    set_theta(payload, theta):
        _theta = int((theta +3.1415926535897931) / 0.0000958737992429)
        payload[5] = ((_theta >> 12) & 0b00001111) | (payload[5] & 0b11110000);
        payload[6] = (_theta >> 8);
        payload[7] = ((_theta >> 8) & 0b11110000) | (payload[7] & 0b00001111);

    @staticmethod
    set_angle(payload, angle):
        _angle = int((angle +3.1415926535897931) / 0.0000958737992429)
        payload[7] = ((_angle >> 12) & 0b00001111) | (payload[7] & 0b11110000);
        payload[8] = (_angle >> 8);
        payload[9] = ((_angle >> 8) & 0b11110000) | (payload[9] & 0b00001111);

    @staticmethod
    set_wheelLocked(payload, wheelLocked):
        payload[9] = (wheelLocked & 0b00001111) | (payload[9] & 0b11110000);

    @staticmethod
    set_wheelBraking(payload, wheelBraking):
        payload[10] = ((wheelBraking << 4) & 0b11110000) | (payload[10] & 0b00001111);

    @staticmethod
    set_rssi(payload, rssi):
        payload[10] = (rssi & 0b00001111) | (payload[10] & 0b11110000);

# ================================ ENCODE ================================
    def encode(self):
        payload = np.zeros(BaseTypes.PACKET_SIZE_ROBOT_FEEDBACK, dtype=np.uint8)
        RobotFeedback.set_header              (payload, self.header)
        RobotFeedback.set_id                  (payload, self.id)
        RobotFeedback.set_messageId           (payload, self.messageId)
        RobotFeedback.set_batteryLevel        (payload, self.batteryLevel)
        RobotFeedback.set_XsensCalibrated     (payload, self.XsensCalibrated)
        RobotFeedback.set_ballSensorWorking   (payload, self.ballSensorWorking)
        RobotFeedback.set_hasBall             (payload, self.hasBall)
        RobotFeedback.set_capacitorCharged    (payload, self.capacitorCharged)
        RobotFeedback.set_ballPos             (payload, self.ballPos)
        RobotFeedback.set_rho                 (payload, self.rho)
        RobotFeedback.set_theta               (payload, self.theta)
        RobotFeedback.set_angle               (payload, self.angle)
        RobotFeedback.set_wheelLocked         (payload, self.wheelLocked)
        RobotFeedback.set_wheelBraking        (payload, self.wheelBraking)
        RobotFeedback.set_rssi                (payload, self.rssi)
        return payload


# ================================ DECODE ================================
    def decode(self, payload):
        self.header           = RobotFeedback.get_header(payload)
        self.id               = RobotFeedback.get_id(payload)
        self.messageId        = RobotFeedback.get_messageId(payload)
        self.batteryLevel     = RobotFeedback.get_batteryLevel(payload)
        self.XsensCalibrated  = RobotFeedback.get_XsensCalibrated(payload)
        self.ballSensorWorking= RobotFeedback.get_ballSensorWorking(payload)
        self.hasBall          = RobotFeedback.get_hasBall(payload)
        self.capacitorCharged = RobotFeedback.get_capacitorCharged(payload)
        self.ballPos          = RobotFeedback.get_ballPos(payload)
        self.rho              = RobotFeedback.get_rho(payload)
        self.theta            = RobotFeedback.get_theta(payload)
        self.angle            = RobotFeedback.get_angle(payload)
        self.wheelLocked      = RobotFeedback.get_wheelLocked(payload)
        self.wheelBraking     = RobotFeedback.get_wheelBraking(payload)
        self.rssi             = RobotFeedback.get_rssi(payload)


    def printBitString(self):        payload = self.encode()        for i in range(len(payload)):            print(format(payload[i], '08b'), end=" ")        print()