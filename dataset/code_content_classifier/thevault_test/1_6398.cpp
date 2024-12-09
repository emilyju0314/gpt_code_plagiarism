float calculateSteepness1(unsigned short *depth_image, int x, int y, int w, int h)
{
	int pos = x + y*w;

	int val = depth_image[pos];
	int v1 = depth_image[pos + 1];
	int v2 = depth_image[pos - 1];
	int v3 = depth_image[pos + w];
	int v4 = depth_image[pos - w];
	int steepness = 0;

	if (v1 != 0)
	steepness = max(steepness, abs(v1 - val));
	if (v2 != 0)
	steepness = max(steepness, abs(v2 - val));
	if (v3 != 0)
	steepness = max(steepness, abs(v3 - val));
	if (v4 != 0)
	steepness = max(steepness, abs(v4 - val));
	return exp(-steepness / 10.0f);
}