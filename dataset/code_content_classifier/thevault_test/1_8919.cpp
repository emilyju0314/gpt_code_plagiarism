void Pipeline::_covarianceXY(const vector<Point> &pts, Mat &covOut, Mat &meanOut) {
  Mat_<double> data(pts.size(),2);
  for (size_t i = 0; i < pts.size(); i++) {
    data(i,0) = pts[i].x;
    data(i,1) = pts[i].y;
  }

  calcCovarMatrix(data, covOut, meanOut, CV_COVAR_NORMAL | CV_COVAR_ROWS);

  if (logLevel >= FIRELOG_TRACE) {
    char buf[200];
    snprintf(buf, sizeof(buf), "covarianceXY() -> covariance:[%f,%f;%f,%f] mean:[%f,%f]",
      covOut.at<double>(0,0), covOut.at<double>(0,1), 
      covOut.at<double>(1,0), covOut.at<double>(1,1),
      meanOut.at<double>(0), meanOut.at<double>(1));
    LOGTRACE1("%s", buf);
  }
}