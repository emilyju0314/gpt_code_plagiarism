char CClientPIC::D_ServoSetGain(byte addr, short int kp, short int kd, short int ki, short int il, byte ol, byte cl, short int el, byte sr, byte dc)
{
  int status;
  
  //set parameters for out_msg
  this->out_msg.id=_D_SERVOSETGAIN;
  this->out_msg.msg.fdServoSetGain.addr=addr;
  this->out_msg.msg.fdServoSetGain.kp=kp;
  this->out_msg.msg.fdServoSetGain.ki=ki;
  this->out_msg.msg.fdServoSetGain.kd=kd;
  this->out_msg.msg.fdServoSetGain.cl=cl;
  this->out_msg.msg.fdServoSetGain.dc=dc;
  this->out_msg.msg.fdServoSetGain.el=el;
  this->out_msg.msg.fdServoSetGain.il=il;
  this->out_msg.msg.fdServoSetGain.ol=ol;
  this->out_msg.msg.fdServoSetGain.sr=sr;
  
  //send out_msg to PIC Daemon who will place reply into in_msg and return
  //0 if no error and -1 otherwise
  status=Send(this->pid,&out_msg,&in_msg,sizeof(out_msg),sizeof(in_msg));
  return(status);
}