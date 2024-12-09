inline void* allocate(size_t size_in_bytes /* write me:, bool recognized_by_all_contexts */)
{
	void* allocated = nullptr;
	// Note: the typed cudaMallocHost also takes its size in bytes, apparently, not in number of elements
	auto result = cudaMallocHost(&allocated, size_in_bytes);
	if (is_success(result) && allocated == nullptr) {
		// Can this even happen? hopefully not
		result = cudaErrorUnknown;
	}
	cuda::throw_if_error(result, "Failed allocating " + std::to_string(size_in_bytes) + " bytes of host memory");
	return allocated;
}