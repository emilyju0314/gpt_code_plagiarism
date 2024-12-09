void Calibrate(){
  //send msg CALIBRATE_ALL to YAPOC
  //right now YAPOC does kismet style calibration, simply set encoder to zero
  //only for axis 0,1,2, 4,5,6,7 (no 3!)
  //all the dofs must be set to their 0 position
  //when this is called
  //this just sets the origins of the dofs
  //axis 3 will have to be calibrated by moving to limits??
  msg.CreateCalibrateAllMsg();
  SendMessage();
}