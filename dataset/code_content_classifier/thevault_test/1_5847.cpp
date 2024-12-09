inline Byte* write_elements(Byte* output, std::error_code& ec, Byte value) noexcept
{
	*output = value;
	return output + 1;
}