void opcontrol() {
	while (true) {
		tilter.setBrakeMode(AbstractMotor::brakeMode::hold);
		rollerL.setBrakeMode(AbstractMotor::brakeMode::hold);
		rollerR.setBrakeMode(AbstractMotor::brakeMode::hold);
		lift.setBrakeMode(AbstractMotor::brakeMode::hold);

		controller.setText(1, 7, std::to_string(lift.getTemperature()));

		//pros::Task drive (driveTask, (void*)"PROS", TASK_PRIORITY_MAX, TASK_STACK_DEPTH_DEFAULT);
		//pros::Task stack (stackTask, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT);
		driveControl();
		driveControl();
		intakeControl();
		magazineControl();
		liftControl();
		descore();
		tilterBack();
		//tilterBack();
		//liftDown is RIGHT button
		//liftComingBack();

		if(midTowerButton.isPressed())
		{
			midTowerMacro();
		}

		// if(lowTowerButton.isPressed())
		// {
		// 	lowTowerMacro();
		// }
		pros::delay(20);
	}
}