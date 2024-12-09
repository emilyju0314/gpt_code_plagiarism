short *MallocPlaneShort(int width, int height, int *pStepBytes)
{
	short *ptr;
	*pStepBytes = ((int)ceil((width*sizeof(short))/16.0f))*16;
	//#ifdef __ALLOW_ALIGNED_MEMORY_MANAGEMENT
	//	ptr = (float *)_aligned_malloc(*pStepBytes * height, 16);
	//#else
	ptr = (short *)malloc(*pStepBytes * height);
	//#endif
	*pStepBytes = *pStepBytes / sizeof(short);
	return ptr;
}