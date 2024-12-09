inline bool is_part_of_a_region_pair(void* ptr)
{
	cudaPointerAttributes attributes;
	auto result = cudaPointerGetAttributes(&attributes, ptr);
	cuda::throw_if_error(result, "Could not obtain device pointer attributes");
#ifdef DEBUG
	auto self_copy = (attributes.memoryType == cudaMemoryTypeHost) ?
		attributes.hostPointer : attributes.devicePointer ;
	if (self_copy != ptr) {
		throw runtime_error(cudaErrorUnknown, "Inconsistent data obtained from the CUDA runtime API");
	}
#endif
	auto corresponding_buffer_ptr =
		(attributes.memoryType == cudaMemoryTypeHost) ?
		attributes.devicePointer : attributes.hostPointer;
	return (corresponding_buffer_ptr != nullptr);
}