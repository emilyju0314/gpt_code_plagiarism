char CClientPIC::D_ResetEncoder(byte addr)
{
	int status;

	this->out_msg.id=_D_RESETENCODER;
	this->out_msg.msg.fdServoSetGain.addr=addr;

	status=Send(this->pid,&out_msg,&in_msg,sizeof(out_msg),sizeof(in_msg));
	return(status);
}