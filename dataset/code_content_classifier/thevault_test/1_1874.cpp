float *MallocPlaneFloat(int width, int height, int *pStepBytes)
{
	float *ptr;
	*pStepBytes = ((int)ceil((width*sizeof(float))/16.0f))*16;
//#ifdef __ALLOW_ALIGNED_MEMORY_MANAGEMENT
//	ptr = (float *)_aligned_malloc(*pStepBytes * height, 16);
//#else
	ptr = (float *)malloc(*pStepBytes * height);
//#endif
	*pStepBytes = *pStepBytes / sizeof(float);
	return ptr;
}