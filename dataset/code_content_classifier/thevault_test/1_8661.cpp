Bytes Prng::rand_bits(size_t bits)
{
	static const byte MASK[8] =
		{ 0xFF, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };

	Bytes rnd;

	while (bits > 128)
	{
		rnd += rand();
		bits -= 128;
	}

	Bytes last = rand();

	last.resize((bits+7)/8);
	last.back() &= MASK[bits%8]; // clear the extra bits

	return rnd + last;
}