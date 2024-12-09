void YARPFft::Convert2DoubleScaled (const unsigned char *in, double *out, int w, int h)
{
	const int size = w * h;
	for (int i = 0; i < size; i++)
	{
		*out++ = double (*in) / 255.0;
		in++;
	}
}