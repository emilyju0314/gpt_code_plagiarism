int YARPOutputSocketMcast::SendReceivingReply(char *reply_buffer, int reply_buffer_length)
{
	ACE_OS::memset (reply_buffer, 0, reply_buffer_length);
	return reply_buffer_length;
}