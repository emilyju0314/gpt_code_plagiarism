int YARPEsdCanDeviceDriver::readBootMemory (void *cmd)
{
	const int axis = *((int *)cmd);
	ACE_ASSERT (axis >= 0 && axis <= (ESD_MAX_CARDS-1)*2);

	return _writeNone (CAN_READ_FLASH_MEM, axis);
}