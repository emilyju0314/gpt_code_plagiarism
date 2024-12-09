KeyPoint Pipeline::_regionKeypoint(const vector<Point> &region) {
  Mat covOut;
  Mat mean;
  Mat eigenvectors;
  _eigenXY(region, eigenvectors, mean, covOut);

  double x = mean.at<double>(0);
  double y = mean.at<double>(1);
  double e0x = eigenvectors.at<double>(0,0);
  double e0y = eigenvectors.at<double>(0,1);
  double e1x = eigenvectors.at<double>(1,0);
  double e1y = eigenvectors.at<double>(1,1);
  double radians;
  if (covOut.at<double>(1,0) >= 0) { // Q1
    if (covOut.at<double>(0,0) >= covOut.at<double>(1,1)){ // X >= Y
      if (e0x >= e0y) { // eigenvector X >= Y
        radians = atan2(e0y, e0x);
      } else {
        radians = atan2(e1y, e1x);
      }
    } else { // eigenvector Y < X
      if (e0x >= e0y) {
        radians = atan2(e1y, e1x);
      } else {
        radians = atan2(e0y, e0x);
      }
    }
  } else { // Q2
    if (e0x >= 0 && e0y >= 0) { // eigenvector Q4
      radians = atan2(e1y, e1x);
    } else { // eigenvector Q2
      radians = atan2(e0y, e0x);
    }
  }

  double degrees = radians * 180./CV_PI;
  if (degrees < 0) {
    degrees = degrees + 360;
  } else if (degrees >= 135) {
    degrees = degrees + 180;
  }

  double diam = 2*sqrt(region.size()/CV_PI);
  LOGTRACE4("regionKeypoint() -> x:%f y:%f diam:%f angle:%f", x, y, diam, degrees);

  return KeyPoint((float) x, (float) y, (float) diam, (float) degrees);
}