void initialize() {
	// very important to use if u are not using
	// if delete this line, then have to use pro:: to avoid errors
	using namespace pros;
	lcd::initialize();
	lcd::set_text(1, "Hello PROS User!");
	// drive motors
	Motor leftFront(9,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
	Motor leftBack(2,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
	Motor rightFront(3,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
	Motor rightBack(4,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
	// intake motors
	Motor leftIntake(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_COUNTS);
	Motor rightIntake(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
	// arm motor
	//Motor arm(5, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
	// angleAdjuster motor
	Motor angleAdjuster(6, E_MOTOR_GEARSET_36, false, MOTOR_ENCODER_COUNTS);
	ADIGyro gyro(1);
	//lcd::register_btn1_cb(on_center_button);
	// controller init
	Controller master (E_CONTROLLER_MASTER);
}