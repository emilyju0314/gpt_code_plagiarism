static int uiVideo(const char * pipelinePath, ArgMap &argMap) {
  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened()) {  // check if we succeeded
    LOGERROR("Could not open camera");
    exit(-1);
  }

  namedWindow("image",1);

  Pipeline pipeline(pipelinePath, Pipeline::PATH);

  for(;;) {
    Mat frame;
    cap >> frame; // get a new frame from camera

    json_t *pModel = pipeline.process(frame, argMap);

    // Display pipeline output
    imshow("image", frame);
    if(waitKey(30) >= 0) break;

    // Free model
    json_decref(pModel);
  }

  return 0;
}