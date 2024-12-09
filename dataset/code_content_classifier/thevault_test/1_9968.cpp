inline void copy(void *destination, const void *source, size_t num_bytes, stream::id_t stream_id)
{
	auto result = cudaMemcpyAsync(destination, source, num_bytes, cudaMemcpyDefault, stream_id);
	if (is_failure(result)) {
		std::string error_message("Scheduling a memory copy on stream " + cuda::detail::ptr_as_hex(stream_id));
		// TODO: Determine whether it was from host to device, device to host etc and
		// add this information to the error string
		throw_if_error(result, error_message);
	}
}