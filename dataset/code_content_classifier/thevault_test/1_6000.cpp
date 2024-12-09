void MoveMultipleAxes(int naxes, short *axes, float *pos){
  //function for moving multiple axes at a time
  //naxes = number of axes, axes contains # of axes to be moved, pos contains
  //corresponding requested positions
  //send msg POSITIONCOMMAND to YAPOC with 2 inputs: float[30] containing 
  //requested positions and short[30] containing statusbits
  //YAPOC will only move axes whose statusbits is ON (1) and ignore the ones 
  //that are OFF (0)
  
  //clear all bits first
  for (int i = 0; i < N_AXIS; i++)
    statusbits[i] = OFF;
  
  for (i = 0; i < naxes; i++){
    newpositions[axes[i]] = pos[i];
    statusbits[axes[i]] = ON;
  }

  //make sure to set uselimit_flag to 1 b/c motorcontrol will enforce limits only when uselimit_flag = 1
  short uselimit_flag = 1;
  //command in ticks
  msg.CreatePositionCommandMsg(newpositions,statusbits,uselimit_flag);
  SendMessage();
  
  //set status bit back to zero, just in case
  //the rest of status bits should still be zero
  for ( i = 0; i < naxes; i++){
        statusbits[axes[i]] = OFF;
  }
}