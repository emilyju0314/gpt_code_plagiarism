inline region_pair allocate(
	size_t                           size_in_bytes,
	region_pair::allocation_options  options)
{
	region_pair allocated;
	auto flags = cuda::memory::mapped::detail::make_cuda_host_alloc_flags(options);
	// Note: the typed cudaHostAlloc also takes its size in bytes, apparently,
	// not in number of elements
	auto status = cudaHostAlloc(&allocated.host_side, size_in_bytes, flags);
	if (is_success(status) && (allocated.host_side == nullptr)) {
		// Can this even happen? hopefully not
		status = cudaErrorUnknown;
	}
	if (is_success(status)) {
		auto get_device_pointer_flags = 0u; // see the CUDA runtime documentation
		status = cudaHostGetDevicePointer(
			&allocated.device_side,
			allocated.host_side,
			get_device_pointer_flags);
	}
	throw_if_error(status,
		"Failed allocating a mapped pair of memory regions of size " + std::to_string(size_in_bytes)
			+ " bytes of global memory on device " + std::to_string(cuda::device::current::get_id()));
	return allocated;
}