inline void copy(void *destination, const void *source, size_t num_bytes)
{
	auto result = cudaMemcpy(destination, source, num_bytes, cudaMemcpyDefault);
	if (is_failure(result)) {
		std::string error_message("Synchronously copying data");
		// TODO: Determine whether it was from host to device, device to host etc and
		// add this information to the error string
		throw_if_error(result, error_message);
	}
}