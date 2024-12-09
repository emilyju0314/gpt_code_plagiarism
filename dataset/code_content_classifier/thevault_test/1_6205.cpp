int YARPOutputSocketMulti::SendReceivingReply(char *reply_buffer, int reply_buffer_length)
{
#ifdef DONT_WAIT_UP
  if (getRequireAck()) 
  {
#endif
	OSDataMulti& d = OSDATA(system_resources);
	MyMessageHeader hdr2;
	hdr2.SetBad ();

	int result = -1;
	int r = d._stream.recv_n ((void *)(&hdr2), sizeof(hdr2), 0);
	if (r == sizeof(hdr2))
	{
		int len2 = hdr2.GetLength();
		if (len2 > 0)
		{
			if (len2 < reply_buffer_length)
			{
				reply_buffer_length = len2;
			}

			result = d._stream.recv_n ((void *)reply_buffer, reply_buffer_length, 0);
		}
		else
		{
			if (len2 == 0) { result = 0; }
		}
	}
	return result;
#ifdef DONT_WAIT_UP
  } else {
	ACE_OS::memset (reply_buffer, 0, reply_buffer_length);
	return reply_buffer_length;
  }
#endif
}