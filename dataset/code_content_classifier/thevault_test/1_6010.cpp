char CClientPIC::D_ReadEncoder(byte addr, char set,int * encoder)
{
	int status;

	
	this->out_msg.id=_D_READENCODER;

	this->out_msg.msg.fdReadEncoder.addr=addr;
	this->out_msg.msg.fdReadEncoder.pos=0;
	this->out_msg.msg.fdReadEncoder.set=set;

     //printf("Sending ReadEncoder to pid = %d for axis %d\n",this->pid,addr);
	status=Send(this->pid,&out_msg,&in_msg,sizeof(out_msg),sizeof(in_msg));

	if (status)
	{	
		return(-1);
	}
	
	*encoder = in_msg.msg.fdReadEncoder.pos;
	
	return(status);
}