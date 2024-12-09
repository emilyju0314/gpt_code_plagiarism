void CClientPIC::D_GetNumMotors()
{
  int status;
  this->out_msg.id = _D_GETNUMMOTORS;
  //this->out_msg.num = num;
  status = Send(this->pid,&out_msg,&in_msg,sizeof(out_msg),sizeof(in_msg));
  nmotors = in_msg.msg.fdGetNumMotors.nmotors;
  printf("Receive nmotors = %d \n",nmotors);
}