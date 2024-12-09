void usercontrol( void ) {
  // User control code here, inside the loop

  robot.startFlywheel();
  robot.setFlywheelSpeed(180);

  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
    robot.drive(primary.Axis1.position(), primary.Axis3.position());
    
    if(primary.ButtonL1.pressing())
      robot.intake(INTAKE_MODE_IN);
    else if(primary.ButtonL2.pressing())
      robot.intake(INTAKE_MODE_OUT);
    else 
      robot.intake(INTAKE_MODE_STOP);
    
    if(primary.ButtonA.pressing())
      robot.lift(LIFT_MODE_UP);
    else if(primary.ButtonB.pressing())
      robot.lift(LIFT_MODE_DOWN);
    else
      robot.lift(LIFT_MODE_HOLD);
    
    robot.engageFlywheel(primary.ButtonR1.pressing());
    if(primary.ButtonR2.pressing())
      robot.modifiedDoubleShot(1.5);

    if(primary.ButtonLeft.pressing()) {
      robot.startFlywheel();
    }

    if(primary.ButtonRight.pressing()) {
      robot.setFlywheelSpeed(150);
    }

    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}