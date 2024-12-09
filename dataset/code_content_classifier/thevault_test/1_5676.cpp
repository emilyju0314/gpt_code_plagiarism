int SHA1Input(SHA1Context *context, const uint8_t *message_array, unsigned length) {
	if (!length) {			//condition for length
		return shaOk;
	}
	if (!context || !message_array) { //condition for no message array
		return shaNull;
	}
	if (context->Computed) {
		context->Corrupted = shaError; // condition to check corrupted bits
		return shaError;
	}
	if (context->Corrupted) {
		return context->Corrupted; // condition to check corrupted bits
	}
	while (length-- && !context->Corrupted)
	{
		context->Message_Block[context->Message_Block_Index++] = (*message_array & 0xFF);
		context->Length_Low += 8;
		if (context->Length_Low == 0) {
			context->Length_High++;
			if (context->Length_High == 0) {
				/* Message is too long*/
				context->Corrupted = 1;
			}
		}
		if (context->Message_Block_Index == 64) {
			SHA1ProcessMessageBlock(context);
		}
		message_array++;
	}
	return shaOk;
}