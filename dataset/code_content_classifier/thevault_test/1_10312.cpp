inline static double sfmt_genrand_res53_mix(sfmt_t * sfmt)
	{
		uint32_t x, y;

		x = sfmt_genrand_uint32(sfmt);
		y = sfmt_genrand_uint32(sfmt);
		return sfmt_to_res53_mix(x, y);
	}