static int uiStill(const char * pipelinePath, Mat &image, ArgMap &argMap, bool isTime, int jsonIndent, int jsonPrecision) {
  Pipeline pipeline(pipelinePath, Pipeline::PATH);
  
  json_t *pModel = pipeline.process(image, argMap);

  if (isTime) {
    long long tickStart = cvGetTickCount();
    //cout << "cvGetTickCount()" << cvGetTickCount() << endl;
    //cout << "tickStart" << tickStart << endl;
    int iterations = 100;
    for (int i=0; i < iterations; i++) {
      json_decref(pModel);
      pModel = pipeline.process(image, argMap);
    }
    float ticksElapsed = cvGetTickCount() - tickStart;
    //cout << "ticksElapsed:" << ticksElapsed << endl;
    float msElapsed = ticksElapsed/cvGetTickFrequency()*1E-3;
    //cout << "msElapsed:" << msElapsed << endl;
    float msIter = msElapsed/iterations;
    //cout << "msIter:" << msIter << endl;
    LOGINFO2("timed %d iterations with an average of %.1fms per iteration", iterations, msIter);
  }

  // Print out returned model 
  char *pModelStr = json_dumps(pModel, JSON_PRESERVE_ORDER|JSON_COMPACT|JSON_INDENT(jsonIndent)|JSON_REAL_PRECISION(jsonPrecision));
  cout << pModelStr << endl;
  free(pModelStr);

  // Free model
  json_decref(pModel);

  return 0;
}