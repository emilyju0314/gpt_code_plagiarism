CvSeq* cvLatentSvmDetectObjects(IplImage* image, 
								CvLatentSvmDetector* detector, 
								CvMemStorage* storage, 
								float overlap_threshold, int numThreads)
{
	CvLSVMFeaturePyramid *H = 0;
    CvPoint *points = 0, *oppPoints = 0;
    int kPoints = 0;
    float *score = 0;    
    unsigned int maxXBorder = 0, maxYBorder = 0;
	int numBoxesOut = 0;
	CvPoint *pointsOut = 0;
	CvPoint *oppPointsOut = 0; 
    float *scoreOut = 0;
	CvSeq* result_seq = 0;
    int error = 0;

    cvConvertImage(image, image, CV_CVTIMG_SWAP_RB);
    // Getting maximum filter dimensions
	getMaxFilterDims((const CvLSVMFilterObject**)(detector->filters), detector->num_components, 
                     detector->num_part_filters, &maxXBorder, &maxYBorder);
    // Create feature pyramid with nullable border
    H = createFeaturePyramidWithBorder(image, maxXBorder, maxYBorder);
    // Search object
    error = searchObjectThresholdSomeComponents(H, (const CvLSVMFilterObject**)(detector->filters), 
        detector->num_components, detector->num_part_filters, detector->b, detector->score_threshold, 
        &points, &oppPoints, &score, &kPoints, numThreads);
    if (error != LATENT_SVM_OK)
    {
        return NULL;
    }
    // Clipping boxes
    clippingBoxes(image->width, image->height, points, kPoints);
    clippingBoxes(image->width, image->height, oppPoints, kPoints);
    // NMS procedure
    nonMaximumSuppression(kPoints, points, oppPoints, score, overlap_threshold,
                &numBoxesOut, &pointsOut, &oppPointsOut, &scoreOut);

	result_seq = cvCreateSeq( 0, sizeof(CvSeq), sizeof(CvObjectDetection), storage );

	for (int i = 0; i < numBoxesOut; i++)
	{
		CvObjectDetection detection = {{0, 0, 0, 0}, 0};
		detection.score = scoreOut[i];
		CvRect bounding_box = {0, 0, 0, 0};
		bounding_box.x = pointsOut[i].x;
		bounding_box.y = pointsOut[i].y;
		bounding_box.width = oppPointsOut[i].x - pointsOut[i].x;
		bounding_box.height = oppPointsOut[i].y - pointsOut[i].y;
		detection.rect = bounding_box;
		cvSeqPush(result_seq, &detection);
	}
    cvConvertImage(image, image, CV_CVTIMG_SWAP_RB);

    freeFeaturePyramidObject(&H);
    free(points);
    free(oppPoints);
    free(score);

	return result_seq;
}