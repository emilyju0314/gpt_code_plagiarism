inline void free(region_pair pair)
{
	auto result = cudaFreeHost(pair.host_side);
	cuda::throw_if_error(result, "Could not free mapped memory region pair.");
}