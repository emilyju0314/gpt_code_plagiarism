inline void free(void* ptr)
{
	auto result = cudaFree(ptr);
	cuda::throw_if_error(result, "Freeing device memory at 0x" + cuda::detail::ptr_as_hex(ptr));
}