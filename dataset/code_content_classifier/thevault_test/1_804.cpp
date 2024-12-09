void cvReleaseLatentSvmDetector(CvLatentSvmDetector** detector)
{
	free((*detector)->b);
	free((*detector)->num_part_filters);
	for (int i = 0; i < (*detector)->num_filters; i++)
	{
		free((*detector)->filters[i]->H);
		free((*detector)->filters[i]);
	}
	free((*detector)->filters);
	free((*detector));
	*detector = 0;
}