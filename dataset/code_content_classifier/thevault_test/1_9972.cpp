inline void deregister(void *ptr)
{
	auto result = cudaHostUnregister(ptr);
	cuda::throw_if_error(result,
		"Could not unregister the memory segment starting at address *a");
}