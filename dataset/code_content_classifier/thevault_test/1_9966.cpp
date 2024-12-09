inline void* allocate(cuda::device::id_t device_id, size_t size_in_bytes)
{
	cuda::device::current::scoped_override_t<> set_device_for_this_scope(device_id);
	return memory::device::detail::allocate(size_in_bytes);
}