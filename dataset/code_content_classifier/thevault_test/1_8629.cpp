Buffer::Buffer (int size)
    : bufferSize (size)
{
	buffer.allocate (bufferSize, true);
}