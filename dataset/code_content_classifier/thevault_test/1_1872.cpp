byte *MallocPlaneByte(int width, int height, int *pStepBytes)
{
	byte *ptr;
	*pStepBytes = ((int)ceil(width/16.0f))*16;
//#ifdef __ALLOW_ALIGNED_MEMORY_MANAGEMENT
//	ptr = (byte *)_aligned_malloc(*pStepBytes * height, 16);
//#else
	ptr = (byte *)malloc(*pStepBytes * height);
//#endif
	return ptr;
}