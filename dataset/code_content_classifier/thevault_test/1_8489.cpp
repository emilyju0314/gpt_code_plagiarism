void Pipeline::Process(){
	//Step Blur0:
	//input
	cv::Mat blur0Input = source0;
	BlurType blur0Type = BlurType::GAUSSIAN;
	double blur0Radius = 1.8018018018018018;  // default Double
	blur(blur0Input, blur0Type, blur0Radius, this->blur0Output);
	//Step Blur1:
	//input
	cv::Mat blur1Input = blur0Output;
	BlurType blur1Type = BlurType::BOX;
	double blur1Radius = 0.0;  // default Double
	blur(blur1Input, blur1Type, blur1Radius, this->blur1Output);
	//Step HSL_Threshold0:
	//input
	cv::Mat hslThresholdInput = blur1Output;
	double hslThresholdHue[] = {51.798561151079134, 99.01528013582343};
	double hslThresholdSaturation[] = {68.79496402877697, 255.0};
	double hslThresholdLuminance[] = {36.690647482014384, 166.2478777589134};
	hslThreshold(hslThresholdInput, hslThresholdHue, hslThresholdSaturation, hslThresholdLuminance, this->hslThresholdOutput);
	//Step Find_Contours0:
	//input
	cv::Mat findContoursInput = hslThresholdOutput;
	bool findContoursExternalOnly = false;  // default Boolean
	findContours(findContoursInput, findContoursExternalOnly, this->findContoursOutput);
	//Step Filter_Contours0:
	//input
	std::vector<std::vector<cv::Point> > filterContoursContours = findContoursOutput;
	double filterContoursMinArea = 600.0;  // default Double
	double filterContoursMinPerimeter = 0.0;  // default Double
	double filterContoursMinWidth = 0.0;  // default Double
	double filterContoursMaxWidth = 1000.0;  // default Double
	double filterContoursMinHeight = 0.0;  // default Double
	double filterContoursMaxHeight = 1000.0;  // default Double
	double filterContoursSolidity[] = {0, 100};
	double filterContoursMaxVertices = 1000000.0;  // default Double
	double filterContoursMinVertices = 0.0;  // default Double
	double filterContoursMinRatio = 0.0;  // default Double
	double filterContoursMaxRatio = 1000.0;  // default Double
	filterContours(filterContoursContours, filterContoursMinArea, filterContoursMinPerimeter, filterContoursMinWidth, filterContoursMaxWidth, filterContoursMinHeight, filterContoursMaxHeight, filterContoursSolidity, filterContoursMaxVertices, filterContoursMinVertices, filterContoursMinRatio, filterContoursMaxRatio, this->filterContoursOutput);
	//Step Convex_Hulls0:
	//input
	std::vector<std::vector<cv::Point> > convexHullsContours = filterContoursOutput;
	convexHulls(convexHullsContours, this->convexHullsOutput);
}