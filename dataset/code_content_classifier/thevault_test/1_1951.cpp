void executive::NVIDIAExecutableKernel::setKernelShape(int x, int y, int z) {
	CUresult result = cuda::CudaDriver::cuFuncSetBlockShape(cuFunction, x, y, z);
	if (result != CUDA_SUCCESS) {
		report("failed to set kernel shape with result " << result);
		throw hydrazine::Exception("NVIDIAExecutableKernel::setKernelShape() failed");
	}
}