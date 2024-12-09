cudaError_t cuda::CudaRuntime::cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr,
	int value, struct cudaExtent extent) {

	cudaError_t result = cudaErrorInvalidValue;

	size_t pitch = pitchedDevPtr.pitch;
	//size_t xsize = pitchedDevPtr.xsize;
	size_t ysize = pitchedDevPtr.ysize;
	size_t width = extent.width;
	size_t height = extent.height;
	size_t depth = extent.depth;
	void *ptr;
	for (size_t i = 0; i < depth; i++) {
		ptr = (char*)pitchedDevPtr.ptr + i * pitch * ysize;
		result = cudaMemset2D(ptr, pitch, value, width, height);
	}
	
	return _setLastError(result);	
}