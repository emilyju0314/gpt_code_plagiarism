void Pipeline::_eigenXY(const vector<Point> &pts, Mat &eigenvectorsOut, Mat &meanOut, Mat &covOut) {
  _covarianceXY(pts, covOut, meanOut);

  Mat eigenvalues;
  eigen(covOut, eigenvalues, eigenvectorsOut);

  LOGTRACE4("eigenXY() -> [%f,%f;%f,%f]",
    eigenvectorsOut.at<double>(0,0), eigenvectorsOut.at<double>(0,1),
    eigenvectorsOut.at<double>(1,0), eigenvectorsOut.at<double>(1,1));
}