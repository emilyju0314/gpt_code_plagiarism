inline Byte* write_elements(Byte* output, std::error_code& ec, std::uint16_t value) noexcept
{
	output[0] = static_cast<Byte>(value >> 8);
	output[1] = static_cast<Byte>(value & 0xff);
	return output + 2;
}