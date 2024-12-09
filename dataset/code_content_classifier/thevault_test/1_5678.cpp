void SHA1PadMessage(SHA1Context *context) {
	/*
	*  Check to see if the current message block is too small to hold
	*  the initial padding bits and length.  If so, we will pad the
	*  block, process it, and then continue padding into a second
	*  block.
	*/
	if (context->Message_Block_Index > 35)
	{
		while (context->Message_Block_Index < 64)
		{
			context->Message_Block[context->Message_Block_Index++] = 0;
		}

		SHA1ProcessMessageBlock(context);

		while (context->Message_Block_Index < 36)
		{
			context->Message_Block[context->Message_Block_Index++] = 0;
		}
	}
	else
	{
		while (context->Message_Block_Index < 36)
		{
			context->Message_Block[context->Message_Block_Index++] = 0;
		}
	}
	/* SHA-1 of Huffman compressed codes are taken as input*/
	string line;
	ifstream inputfile("Huffman_SHA1_input.txt", ios::out);
	if (inputfile.is_open())
	{
		int index = 0;
		while (std::getline(inputfile, line))
		{
			istream& getline(inputfile >> line);
		}
	}

	int blockNumber = 35;
	string startingNumber = "";
	vector<string> sep = split(line, ' '); //Dynamic vector holds the Hash values from text file.
	for (unsigned int i = 0; i < sep.size(); ++i) {
		startingNumber = sep[i];
		text(blockNumber); // Call Text function
		blockNumber = assignBlockNumber;
		int num = stoi(startingNumber, 0, 16); //Convert String to Hexadecimal
		context->Message_Block[assignBlockNumber] = num; //Assign hash values values to Blocks 36 to 55. 
	}

	/*
	*  Store the message length as the last 8 octets
	*/
	context->Message_Block[56] = context->Length_High >> 24;
	context->Message_Block[57] = context->Length_High >> 16;
	context->Message_Block[58] = context->Length_High >> 8;
	context->Message_Block[59] = context->Length_High;
	context->Message_Block[60] = context->Length_Low >> 24;
	context->Message_Block[61] = context->Length_Low >> 16;
	context->Message_Block[62] = context->Length_Low >> 8;
	context->Message_Block[63] = context->Length_Low;

	SHA1ProcessMessageBlock(context);
}