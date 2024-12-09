char CClientPIC::D_MovePosNoWait(byte addr, byte mode, long pos, long vel, long acc, byte pwm, short uselimit_flag)
{
  //check first if motor has been calibrated (unless uselimit_flag is 0 which
  //means that this is a move for calibration
  if (calibrated[addr-1] == 1 || uselimit_flag == 0){

    if (uselimit_flag == 1){
      printf("Checking limits\n");
      //now check if pos is within limits_min & max
      if (pos < limits_min[addr-1]){
	if (DEBUG) printf("Pos = %d < limits_min = %d",pos,limits_min[addr-1]);
	//change pos to limits_min + 1
	pos = limits_min[addr-1] + 1;
	if (DEBUG) printf(", change pos to %d\n",pos);
      }
      if (pos > limits_max[addr-1]){
	if (DEBUG) printf("Pos = %d > limits_max = %d",pos,limits_max[addr-1]);
	//change pos to limits_max - 1
	pos = limits_max[addr-1] - 1;
	if (DEBUG) printf(", change pos to %d\n",pos);
      }
    }	

    int status;
    //set parameters for out_msg
    this->out_msg.id=_D_MOVEPOSNOWAIT;    
    this->out_msg.msg.fdServoLoadTraj.addr=addr;
    this->out_msg.msg.fdServoLoadTraj.acc=acc;
    this->out_msg.msg.fdServoLoadTraj.mode=mode;
    this->out_msg.msg.fdServoLoadTraj.pos=pos;
    this->out_msg.msg.fdServoLoadTraj.pwm=pwm;
    this->out_msg.msg.fdServoLoadTraj.vel=vel;
    
    //send out_msg to PIC Daemon who will place reply into in_msg and return
    //0 if no error and -1 otherwise
    status=Send(this->pid,&out_msg,&in_msg,sizeof(out_msg),sizeof(in_msg));
    return(status);
  }
  else {
    //if not calibrated
    printf("Motor addr %d has not been calibrated. Ignore move.\n",addr);
    return 0;
  }
}