inline region_pair allocate(
	cuda::device::id_t               device_id,
	size_t                           size_in_bytes,
	region_pair::allocation_options  options = {
		region_pair::isnt_portable_across_cuda_contexts,
		region_pair::without_cpu_write_combining }
	)
{
	cuda::device::current::scoped_override_t<> set_device_for_this_scope(device_id);
	return detail::allocate(size_in_bytes, options);
}