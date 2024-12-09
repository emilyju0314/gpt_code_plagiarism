void ChangeVelocity(int naxes, short *axes, float *newvel){
  //function for setting velocity for multiple axes at a time
  //send msg SET_VELOCITY to YAPOC with 2 inputs: float[30] containing requested
  //velocities and short[30] containing statusbits
  //YAPOC will only set velocity for axes whose statusbit is ON (1) and ignore
  //the ones that are OFF (0)
  float newvelocity_rad[N_AXIS];
  
  for (int i = 0; i < naxes; i++){
    statusbits[axes[i]] = ON;
    newvelocity[axes[i]] = newvel[i];
    if(DEBUG) printf("axis %d statusbits = %d newvel = %f\n",axes[i],statusbits[axes[i]], newvel[i]);
  }
  //YAPOC expects requested velocities to be in ticks, thus ConvertFromRadian is
  //used since velocity is set up in radians in this client code
  msg.CreateSetVelocityMsg(msg.ConvertFromRadian(newvelocity, newvelocity_rad),statusbits);
  SendMessage();
  
  //set status bit back to zero, just in case
  //the rest of status bits should still be zero
  for ( i = 0; i < naxes; i++){
    statusbits[axes[i]] = OFF;
  }
  
  
}