void PacketStream::fromCharArray(char* arrayIn)
{
	//clear previous contents of inputStream
	inputStream.str("");
	//place recieved contents to inputStream
	inputStream.str(arrayIn);
}