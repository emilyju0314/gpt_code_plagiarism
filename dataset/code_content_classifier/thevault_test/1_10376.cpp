void AddTrainingEntriesFromCenter(IntegralHogDetector* detector,
                                  const vector<string>& imageFiles,
                                  float label) {
  for (vector<string>::const_iterator imageFile = imageFiles.begin();
       imageFile != imageFiles.end(); ++imageFile) {
    ROS_DEBUG_STREAM("Extracting HOG descriptors from " << *imageFile);

    // Start by opening the image
    Mat image = imread(*imageFile);

    // Find the winSize_ window in the center of the image
    cv::Rect win((image.cols - FLAGS_winW) / 2,
                 (image.rows - FLAGS_winH) / 2,
                 FLAGS_winW,
                 FLAGS_winH);

    detector->AddRegionsForTraining(image, vector<Rect>(1, win),
                                    vector<float>(1, label));

  }
}