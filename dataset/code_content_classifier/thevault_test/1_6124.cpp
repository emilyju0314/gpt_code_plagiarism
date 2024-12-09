IPLAPIIMPL(void, iplConvolve2DFP,(IplImage* srcImage, IplImage* dstImage,
                IplConvKernelFP** kernel, int nKernels, int combineMethod))
{
	// INPLACE: the first time it need to allocate the wk array.
	// I do not really like this solution, it would be much better to
	// alloc the array together with the Kernel.
	// clearly this is also a memory LEAK!
	static float *__tmp_res = NULL;
	static int __tmp_size = -1;

	assert (nKernels == 1);
	// implemented only 1 kernel.

	// do not consider anchor, borders are not set, and assumes
	// that the kernel has odd dimensions (both x and y).

	IplConvKernelFP *ktmp = *kernel;
	float *values = ktmp->values;
	const int ksize = ktmp->nCols * ktmp->nRows;

	assert ((ktmp->nCols % 2) != 0);
	assert ((ktmp->nRows % 2) != 0);

	const int kcols = ktmp->nCols;
	const int krows = ktmp->nRows;
	const int borderx = kcols / 2;
	const int bordery = krows / 2;
	const int w = srcImage->width;
	const int h = srcImage->height;

	assert (compareHeader (srcImage, dstImage));
	assert (srcImage->nChannels == 1);	// Mono images only.
	assert (srcImage->depth == IPL_DEPTH_32F);

	if (__tmp_res == NULL)
	{
		__tmp_size = dstImage->imageSize / sizeof(float);
		///__tmp_res = new float[dstImage->imageSize / sizeof(float)];
		__tmp_res = AllocAligned<float> (dstImage->imageSize / sizeof(float));
		assert (__tmp_res != NULL);
	}
	else
	{
		if (__tmp_size < (int)(dstImage->imageSize / sizeof(float)))
		{
			// new size.
			///delete[] __tmp_res;
			FreeAligned<float> (__tmp_res);
			__tmp_size = dstImage->imageSize / sizeof(float);
			///__tmp_res = new float[dstImage->imageSize / sizeof(float)];
			__tmp_res = AllocAligned<float> (dstImage->imageSize / sizeof(float));
			assert (__tmp_res != NULL);
		}
	}

	if (srcImage != dstImage)
	{
		float tmp;
		float *source = (float *)srcImage->imageData;
		float *dest = (float *)dstImage->imageData;
		for (int i = bordery; i <  h - bordery; i++)
		{
			for (int j = borderx; j < w - borderx; j++)
			{
				tmp = 0;
				for (int k = 0; k < krows; k++)
					for (int l = 0; l < kcols; l++)
					{
						tmp += source[(i + k - bordery) * w + j + l - borderx] 
							* values[ksize - k * kcols - l - 1];
					}
				dest[i * w + j] = tmp;
			}
		}
	}
	else
	{
		// inplace.
		float tmp;
		float *source = (float *)srcImage->imageData;
		float *dest = (float *)dstImage->imageData;
		for (int i = bordery; i <  h - bordery; i++)
		{
			for (int j = borderx; j < w - borderx; j++)
			{
				tmp = 0;
				for (int k = 0; k < krows; k++)
					for (int l = 0; l < kcols; l++)
					{
						tmp += source[(i + k - bordery) * w + j + l - borderx] 
							* values[ksize - k * kcols - l - 1];
					}
				__tmp_res[i * w + j] = tmp;
			}
		}

		memcpy (dstImage->imageData, __tmp_res, dstImage->imageSize);
	}
}