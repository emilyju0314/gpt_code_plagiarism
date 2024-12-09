void icvAppendVec(CvVecFile &in, CvVecFile &out, int *showsamples, int winwidth, int winheight)
{
	CvMat* sample;

	if (*showsamples)
	{
		cvNamedWindow("Sample", CV_WINDOW_AUTOSIZE);
	}
	if (!feof(in.input))
	{
		in.last = 0;
		if (*showsamples)
		{
			if (in.vecsize != winheight * winwidth)
			{
				fprintf(stderr, "ERROR: -show: the size of images inside of vec files does not match with %d x %d, but %d\n", winheight, winwidth, in.vecsize);
				exit(1);
			}
			sample = cvCreateMat(winheight, winwidth, CV_8UC1);
		}
		else
		{
			sample = cvCreateMat(in.vecsize, 1, CV_8UC1);
		}
		for (int i = 0; i < in.count; i++)
		{
			auto s = cvarrToMat(sample);
			icvGetTraininDataFromVec(s, in);
			icvWriteVecSample(out.input, s);
			if (*showsamples)
			{
				cvShowImage("Sample", sample);
				if (cvWaitKey(0) == 27)
				{
					*showsamples = 0;
				}
			}
		}
		cvReleaseMat(&sample);
	}
}