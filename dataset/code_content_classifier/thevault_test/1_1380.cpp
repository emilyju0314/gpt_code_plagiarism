float OpenSimplexNoise::get_multi_noise_4d(float x, float y, float z, float w) const {
	float frequency = 1.0f;
	float amplitude = 1.0f;
	float sum = 0.0f;

	for (int i = 0; i < octaves; i++) {
		sum += get_simplex_noise_4d(x * frequency, y * frequency, z * frequency, w * frequency) * amplitude;
		frequency *= lacunarity;
		amplitude *= persistence;
	}

	return sum;
}