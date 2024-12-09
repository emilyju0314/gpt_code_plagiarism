void DriveTrain::GyroCrab(float x, float y, float desiredAngle, bool operatorControl) {
	auto currentAngle = Robot::gyroSub->PIDGet();
	auto twist = -(desiredAngle - currentAngle);

	while (twist > 180.0) {
		twist -= 360.0;
	}
	while (twist < -180.0) {
		twist += 360.0;
	}

	constexpr float GYRO_P = 0.028; //original is 0.007
	constexpr float GYRO_MAX = 0.3;

	twist = std::min<float>(GYRO_MAX, std::max<float>(-GYRO_MAX, twist * GYRO_P)); //is this correct?
	Crab(twist, y, x, true);
}