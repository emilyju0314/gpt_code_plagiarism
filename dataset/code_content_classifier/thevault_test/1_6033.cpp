void Calibrate(){
    //send msg CALIBRATE_ALL to YAPOC
    //this simply means that all the dofs are set to their 0 position
    //and set their calibrated flags to 1.
     msg.CreateCalibrateAllMsg();
    SendMessage();
}