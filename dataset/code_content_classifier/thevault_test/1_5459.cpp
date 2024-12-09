static void bloomResize(uvec2 size)
{
	ASSERT(size.x > 0);
	ASSERT(size.y > 0);
	if (size.x == currentSize.x && size.y == currentSize.y) return;
	currentSize.x = size.x;
	currentSize.y = size.y;

	for (size_t i = 0; i < BloomPasses; i += 1) {
		uvec2 layerSize = {
			size.x >> (i + 1),
			size.y >> (i + 1)
		};
		bloomFbColor[i].resize(layerSize);
	}
}