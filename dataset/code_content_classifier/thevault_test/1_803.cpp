CvLatentSvmDetector* cvLoadLatentSvmDetector(const char* filename)
{
	CvLatentSvmDetector* detector = 0;
	CvLSVMFilterObject** filters = 0;
	int kFilters = 0;
	int kComponents = 0;
	int* kPartFilters = 0;
	float* b = 0;
	float scoreThreshold = 0.f;
	int err_code = 0;

	err_code = loadModel(filename, &filters, &kFilters, &kComponents, &kPartFilters, &b, &scoreThreshold);
	if (err_code != LATENT_SVM_OK) return 0;

	detector = (CvLatentSvmDetector*)malloc(sizeof(CvLatentSvmDetector));
	detector->filters = filters;
	detector->b = b;
	detector->num_components = kComponents;
	detector->num_filters = kFilters;
	detector->num_part_filters = kPartFilters;
	detector->score_threshold = scoreThreshold;

	return detector;
}