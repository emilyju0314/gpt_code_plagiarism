void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  robot.startFlywheel();
  //robot.getFlywheelMotor().spin(vex::directionType::rev, 100, vex::percentUnits::pct);
  robot.auton();
}