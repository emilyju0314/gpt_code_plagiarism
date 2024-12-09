void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................  
  int fullTile=550;
  int fullCircle=515;
  bool redSide=false;
  bool blueSide=true;

  if(blueSide){
    robot.deploy();
    vex::task::sleep(100);
    robot.intakeAndMove(fullTile*2.6, 50, 1);
    robot.driveFor(fullTile*-1.5, 50);
    robot.turnFor(.36*fullCircle);
    robot.driveFor(fullTile*1, 50);
    robot.driveFor(fullTile*-.15, 50);
    robot.magazineFor(1700, 1);
    robot.driveFor(fullTile*.1, 50);
    vex::task::sleep(200);
    robot.magazineBack();
    robot.intakeAndMove(fullTile*-1, 50, -1);
  }

  if(redSide)
  {
    robot.intakeAndMove(fullTile*2.6, 50, 1);
    robot.driveFor(fullTile*-1.5, 50);
    robot.turnFor(-.36*fullCircle);
    robot.driveFor(fullTile*.8, 50);
    robot.driveFor(fullTile*-.15, 50);
    robot.magazineFor(1700, 1);
    robot.driveFor(fullTile*.1, 50);
    vex::task::sleep(200);
    robot.magazineBack();
    robot.intakeAndMove(fullTile*-1, 50, -1);
  }
}