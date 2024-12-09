void commandMotorBack(int direction) {
	float speed = 0.5f;
	float fastspeed = 1.0f;
	switch(direction) {
		case KeyboardInput::Idle:
			Car::writeControlMotor(Car::Stop, speed); 
			break;
		case KeyboardInput::GoFastForward:
			speed = fastspeed;
		case KeyboardInput::GoForward:
			Car::writeControlMotor(Car::MoveForward, speed); 
			break;
		case KeyboardInput::GoFastBackward:
			speed = fastspeed;
		case KeyboardInput::GoBackward:
			Car::writeControlMotor(Car::MoveBackward, speed); 
			break;
	}
	LogD << "Keyboard: change propulsion to " << (direction*speed) <<endl;
}