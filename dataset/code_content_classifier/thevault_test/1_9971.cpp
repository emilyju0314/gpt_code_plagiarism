inline void register_(void *ptr, size_t size, unsigned flags)
{
	auto result = cudaHostRegister(ptr, size, flags);
	cuda::throw_if_error(result,
		"Could not register a region of page-locked host memory");
}