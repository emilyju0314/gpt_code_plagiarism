void executive::NVIDIAExecutableKernel::launchGrid(int width, int height,
	int depth) {
	report("executive::NVIDIAExecutableKernel::launchGrid(" << width 
		<< ", " << height << ")");
	CUresult result;

	if (depth != 1) {
		throw hydrazine::Exception("Requested grid depth gretaer than 1, "
			"Ocelot does not support the new cuda driver interface for this "
			"feature, please file a bug against Ocelot.");
	}
	
	if (_cacheConfiguration != ExecutableKernel::CacheConfigurationDefault) {
		result = cuda::CudaDriver::cuFuncSetCacheConfig(cuFunction, 
			_translateCacheConfiguration(_cacheConfiguration));
		report("  - cuFuncSetCacheConfig() failed: " << result);
		throw hydrazine::Exception("cuFuncSetCacheConfig() failed ");
	}

	initializeTraceGenerators();

	result = cuda::CudaDriver::cuLaunchGrid(cuFunction, width, height);
	if (result != CUDA_SUCCESS) {
		report("  - cuLaunchGrid() failed: " << result);
		throw hydrazine::Exception("cuLaunchGrid() failed ");
	}
	else {
		report("  - cuLaunchGrid() succeeded!");
	}
	
	result = cuda::CudaDriver::cuCtxSynchronize();
	if (result != CUDA_SUCCESS) {
		report("  - cuCtxSynchronize() after cuLaunchGrid() failed: " << result);
		throw hydrazine::Exception("cuLaunchGrid() failed " + result);
	}
	else {
		report("  - cuCtxSynchronize() after cuLaunchGrid() succeeded!");
	}
	
	finalizeTraceGenerators();
}