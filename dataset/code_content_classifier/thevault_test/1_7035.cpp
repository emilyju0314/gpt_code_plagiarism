void usercontrol( void ) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
    robot.drive(controller1.Axis2.value());

    if(controller1.Axis1.value()>10)
      robot.strafe(1);
    else if (controller1.Axis1.value()<-10)
      robot.strafe(-1);
    else
      robot.strafe(0);
      
    if(controller1.ButtonR1.pressing())
    {
      robot.turnRight();
    }
    else if(controller1.ButtonL1.pressing())
      robot.turnLeft();
    
    if(controller1.ButtonX.pressing())
    {
      robot.moveMagazine(1);
    }
    else if(controller1.ButtonB.pressing())
    {
      robot.moveMagazine(-1);
    }
    else {
      robot.moveMagazine(0);
    }

    if(controller1.ButtonRight.pressing())
      robot.intake(1);
    else if(controller1.ButtonDown.pressing())
      robot.intake(-1);
    else
      robot.intake(0);
    
  
    if(controller1.ButtonA.pressing())
    {
        robot.lift(1);
        robot.moveMagazine(.75);
    }
    else if(controller1.ButtonY.pressing())
    {
      robot.lift(-1);
      robot.moveMagazine(-.75);
    }
    else
    {
      robot.lift(0);
    }
    
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}