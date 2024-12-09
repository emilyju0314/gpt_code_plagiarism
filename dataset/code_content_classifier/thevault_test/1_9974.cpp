inline void* allocate(
	cuda::device::id_t    device_id,
	size_t                num_bytes,
	initial_visibility_t  initial_visibility = initial_visibility_t::to_all_devices)
{
	cuda::device::current::scoped_override_t<> set_device_for_this_scope(device_id);
	return detail::allocate(num_bytes, initial_visibility);
}