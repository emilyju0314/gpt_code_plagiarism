inline void free(void* managed_ptr)
{
	auto result = cudaFree(managed_ptr);
	cuda::throw_if_error(result,
		"Freeing managed memory (host and device regions) at address 0x"
		+ cuda::detail::ptr_as_hex(managed_ptr));
}