float OpenSimplexNoise::get_multi_noise_2d(float x, float y) const {
	float frequency = 1 / period;
	float amplitude = 1;
	float sum = 0;

	for (int i = 0; i < octaves; i++) {
		sum += get_simplex_noise_2d(x * frequency, y * frequency) * amplitude;
		frequency *= lacunarity;
		amplitude *= persistence;
	}

	return sum;
}