inline device::id_t associated_device(stream::id_t stream_id)
{
	if (stream_id == cuda::stream::default_stream_id) {
		throw std::invalid_argument("Cannot determine device association for the default/null stream");
	}
	for(device::id_t device_index = 0; device_index < device::count(); ++device_index) {
		if (is_associated_with(stream_id, device_index)) { return device_index; }
	}
	throw std::runtime_error(
		"Could not find any device associated with stream " + cuda::detail::ptr_as_hex(stream_id));
}