inline void free_region_pair_of(void* ptr)
{
	cudaPointerAttributes attributes;
	auto result = cudaPointerGetAttributes(&attributes, ptr);
	cuda::throw_if_error(result,
		"Could not obtain the properties for the pointer"
		", being necessary for freeing the region pair it's (supposedly) "
		"associated with.");
	cudaFreeHost(attributes.hostPointer);
}