double Pipeline::jaccardIndex(Mat m1, Mat m2)
{
	/*
		Definition:
		Jaccard Index = TP / (TP + FP + FN)
		m1 defines the groundtruth,
		m2 defines the prediction
	*/
	int TP = 0;
	int TN = 0;
	int FP = 0;
	int FN = 0;

	int* TPptr = &TP;
	int* TNptr = &TN;
	int* FPptr = &FP;
	int* FNptr = &FN;

	confusionMatrix(m1, m2, TPptr, TNptr, FPptr, FNptr);
	// Calculate the Jaccard index
	double jaccardInd = *TPptr * 1.0 / (*TPptr + *FPptr + *FNptr) * 1.0;
	return jaccardInd;
}