inline void* allocate(size_t num_bytes)
{
	void* allocated = nullptr;
	// Note: the typed cudaMalloc also takes its size in bytes, apparently,
	// not in number of elements
	auto status = cudaMalloc(&allocated, num_bytes);
	if (is_success(status) && allocated == nullptr) {
		// Can this even happen? hopefully not
		status = cudaErrorUnknown;
	}
	cuda::throw_if_error(status,
		"Failed allocating " + std::to_string(num_bytes) +
		" bytes of global memory on CUDA device " +
		std::to_string(cuda::device::current::get_id()));
	return allocated;
}