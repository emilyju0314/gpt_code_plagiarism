void opcontrol() {
	while (true) {
		if(driveToggle.isPressed())
    	drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY)/4,(controller.getAnalog(ControllerAnalog::rightX)/2));
		else
			drive->getModel()->arcade((controller.getAnalog(ControllerAnalog::leftY)), (controller.getAnalog(ControllerAnalog::rightX)/2));
		intakeControl();
		magazineControl();
		liftControl();

		//if(right.isPressed()){
		//	tilter.moveRelative(2500, 100);
			//pros::delay(3000);}
		if(left.isPressed()){
			drive->setMaxVelocity(75);
			lift.moveVelocity(-100);
			tilter.moveRelative(2500, 100);
			pros::delay(3000);
			rollerR.moveRelative(-1000,125);
			rollerL.moveRelative(-1000,125);
			drive->moveDistance(-13_in);
		}

		pros::delay(20);
	}
}