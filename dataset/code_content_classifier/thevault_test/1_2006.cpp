void util::KernelExtractorDriver::synchronizeFromDevice() {
	ExtractedDeviceState::GlobalAllocationMap::const_iterator alloc_it = state.globalAllocations.begin();
	for (; alloc_it != state.globalAllocations.end(); ++alloc_it) {
		ExtractedDeviceState::MemoryAllocation *allocation = alloc_it->second;
		CUresult result = cudaDriver.cuMemcpyDtoH(&allocation->data[0], 
			toDevicePtr(allocation->devicePointer), allocation->data.size());
		if (result != CUDA_SUCCESS) {
			// failed
			report("KernelExtractorDriver::synchronizeFromDevice() - failed to copy from device " 
				<< cuda::CudaDriver::toString(result));
			report("  source: " << (void *)allocation->devicePointer);
			break;
		}
	}
	
	ExtractedDeviceState::GlobalVariableMap::iterator global_it = state.globalVariables.begin();
	for (; global_it != state.globalVariables.end(); ++global_it) {
		ExtractedDeviceState::GlobalAllocation *allocation = global_it->second;
		
		CUmodule hModule = inverseModuleLookup(allocation->module);
		CUdeviceptr devicePtr;
		size_t size = 0;
		CUresult result = cudaDriver.cuModuleGetGlobal(&devicePtr, &size, hModule, allocation->name.c_str());
		if (result == CUDA_SUCCESS) {
			assert(allocation->data.size() >= size);
			CUresult result = cudaDriver.cuMemcpyDtoH(&allocation->data[0], devicePtr, 
				allocation->data.size());
			if (result != CUDA_SUCCESS) {
				// failed
				report("KernelExtractorDriver::synchronizeFromDevice() - failed to copy from device " 
					<< cuda::CudaDriver::toString(result));
				report("  source: " << (void *)devicePtr);
				break;
			}
		}
	}
}