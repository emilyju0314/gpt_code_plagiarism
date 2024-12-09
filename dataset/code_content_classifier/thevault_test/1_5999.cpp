void MoveOneAxis(short axis, float pos){
  //function for moving only one axis at a time
  //send msg POSITIONCOMMAND to YAPOC with 2 inputs: float[30] containing 
  //requested positions and short[30] containing statusbits
  //YAPOC will only move axes whose statusbits is ON (1) and ignore the ones 
  //that are OFF (0)
  
  statusbits[axis] = ON;
  newpositions[axis] = pos;
  
  //uselimit_flag is set to 1 b/c we're not calibrating
  short uselimit_flag = 1;
  //command in ticks
  msg.CreatePositionCommandMsg(newpositions,statusbits,uselimit_flag);
  SendMessage();
  
  //set status bit back to zero, just in case
  //the other status bits should still be zero
  statusbits[axis] = OFF;
}