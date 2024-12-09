int SHA1Result(SHA1Context *context,
	uint8_t Message_Digest[Sha1HashSize])
{
	int i;

	if (!context || !Message_Digest)
	{
		return shaNull;
	}

	if (context->Corrupted)
	{
		return context->Corrupted;
	}

	if (!context->Computed)
	{
		SHA1PadMessage(context);
		for (i = 0; i<64; ++i)
		{
			/* message may be sensitive, clear it out */
			context->Message_Block[i] = 0;
		}
		context->Length_Low = 0;    /* and clear length */
		context->Length_High = 0;
		context->Computed = 1;
	}

	for (i = 0; i < Sha1HashSize; ++i)
	{
		Message_Digest[i] = context->Intermediate_Hash[i >> 2]
			>> 8 * (3 - (i & 0x03));
	}

	return shaOk;
}