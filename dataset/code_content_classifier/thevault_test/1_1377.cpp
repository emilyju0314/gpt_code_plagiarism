float OpenSimplexNoise::get_multi_noise_1d(float x) const {
	int i;
	float frequency = 1 / period;
	float amplitude = 1;
	float sum = 0;

	for (i = 0; i < octaves; i++) {
		sum += get_simplex_noise_1d(x * frequency) * amplitude;
		frequency *= lacunarity;
		amplitude *= persistence;
	}

	return sum;
}