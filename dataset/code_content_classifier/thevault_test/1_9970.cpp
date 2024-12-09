inline void free(void* host_ptr)
{
	auto result = cudaFreeHost(host_ptr);
	cuda::throw_if_error(result, "Freeing pinned host memory at 0x" + cuda::detail::ptr_as_hex(host_ptr));
}