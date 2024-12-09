char CClientPIC::D_HardReset()
{
  int status;
  this->out_msg.id = _D_HARDRESET;
  status = Send(this->pid,&out_msg,&in_msg,sizeof(out_msg),sizeof(in_msg));
  return(status);
}