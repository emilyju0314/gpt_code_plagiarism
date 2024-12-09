float calculateSteepness(unsigned short *depth_image, int x, int y, int w, int h)
{
	const int depth_threshold = 20;
	const int neighbourhood_size = 5;
	int half_filter = neighbourhood_size / 2;
	depth_image += y*w + x;
	int sum1 = 0, sum2 = 0;
	unsigned short val1, val2; 
	unsigned short val = *depth_image;
	int n_el1 = 0, n_el2 = 0;

	for (int i = -half_filter; i <= half_filter; i++)
	{
		depth_image += i * w;
		for (int j = -half_filter; j < 0; j++)
		{
			val1 = depth_image[j];
			val2 = depth_image[-j];

			if (val1!=0 && val2!=0 && 
				abs(val1 - val) < depth_threshold &&
				abs(val2 - val) < depth_threshold)
			{
				sum1 += val1;
				sum1 -= val2;
				n_el1++;
			}
		}
		depth_image -= i*w; 
	}
	

	unsigned short *depth_ptr2 = depth_image;
	for (int i = -half_filter; i < 0; i++)
	{
		depth_image += i * w;
		depth_ptr2 -= i*w; 
		for (int j = -half_filter; j <= half_filter; j++)
		{
			val1 = depth_image[j];
			val2 = depth_ptr2[j];

			if (val1 != 0 && val2 != 0 && 
				abs(val1 - val) < depth_threshold &&
				abs(val2 - val) < depth_threshold)
			{
				sum2 += val1;
				sum2 -= val2;
				n_el2++;
			}
		}
		depth_image -= i*w;
		depth_ptr2 += i*w;
	}
	n_el1 = max(n_el1, 1);
	n_el2 = max(n_el2, 1);

	float res = abs(sum1 / n_el1) + abs(sum2 / n_el2);//exp(-sum / 1000.0f);

	return res;
}