cudaError_t cuda::CudaRuntime::cudaBindTexture(size_t *offset, 
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t size) {

	_wait();

	cudaError_t result = cudaErrorInvalidValue;
		
	_lock();
	
	_enumerateDevices();
	if (_devices.empty()) {
		_unlock();
		return _setLastError(cudaErrorNoDevice);
	}

	RegisteredTextureMap::iterator texture = _textures.find((void*)texref);
	if(texture != _textures.end()) {
		try {
			_registerModule(texture->second.module);
		}
		catch(...) {
			_unlock();
			throw;
		}
		
		_bind();
		try {
			_getDevice().bindTexture((void*)devPtr, texture->second.module, 
				texture->second.texture, *texref, *desc, ir::Dim3(size, 1, 1));
			if(offset != 0) *offset = 0;
			result = cudaSuccess;
		}
		catch(hydrazine::Exception&) {
		
		}
		
		_unbind();
	}
	
	report("cudaBindTexture(ref = " << texref 
		<< ", devPtr = " << devPtr << ", size = " << size << ")");

	_unlock();
	return _setLastError(result);
}