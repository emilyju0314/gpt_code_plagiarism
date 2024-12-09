cuda::CudaDriverFrontend::Context * cuda::CudaDriverFrontend::_bind() {

#if REPORT_BASE
	std::cout << "  _bind()" << std::endl;
#endif
	_lock();
	cuda::CudaDriverFrontend::Context *ctx = _getContext();
	if (!ctx->_getDevice().selected()) {
		ctx->_getDevice().select();
	}
	return ctx;
}