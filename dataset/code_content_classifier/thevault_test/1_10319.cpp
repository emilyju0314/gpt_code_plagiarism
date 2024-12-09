inline static void neon_recursion(uint32x4_t * r, uint32x4_t a, uint32x4_t b,
		uint32x4_t c, uint32x4_t d)
	{
		uint32x4_t v, x, y, z;
		static const uint32x4_t vzero = { 0,0,0,0 };
		static const uint32x4_t vmask = { SFMT_MSK1, SFMT_MSK2, SFMT_MSK3, SFMT_MSK4 };

# define rotate_bytes(A, B, C) vreinterpretq_u32_u8(vextq_u8(vreinterpretq_u8_u32(A),vreinterpretq_u8_u32(B),(C)))

		y = vshrq_n_u32(b, SFMT_SR1);
		z = rotate_bytes(c, vzero, SFMT_SR2);
		v = vshlq_n_u32(d, SFMT_SL1);
		z = veorq_u32(z, a);
		z = veorq_u32(z, v);
		x = rotate_bytes(vzero, a, 16 - SFMT_SL2);
		y = vandq_u32(y, vmask);
		z = veorq_u32(z, x);
		z = veorq_u32(z, y);
		*r = z;

# undef rotate_bytes
	}