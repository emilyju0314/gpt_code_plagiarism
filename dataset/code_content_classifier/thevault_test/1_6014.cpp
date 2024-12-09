char CClientPIC::D_IsMoveDone(byte addr)
 {
   int status;
   this->out_msg.id = _D_ISMOVEDONE;
   this->out_msg.msg.fdIsMoveDone.addr = addr;
   status= Send(this->pid,&out_msg, &in_msg, sizeof(out_msg),sizeof(in_msg));
   
   return(in_msg.msg.fdIsMoveDone.done);
 }