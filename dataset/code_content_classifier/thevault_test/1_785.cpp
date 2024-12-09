void HarrisResponse::operator()(std::vector<cv::KeyPoint>& kpts) const
{
  // Those parameters are used to match the OpenCV computation of Harris corners
  float scale = (1 << 2) * 7.0f * 255.0f;
  scale = 1.0f / scale;
  float scale_sq_sq = scale * scale * scale * scale;

  // define it to 1 if you want to compare to what OpenCV computes
#define HARRIS_TEST 0
#if HARRIS_TEST
  cv::Mat_<float> dst;
  cv::cornerHarris(image_, dst, 7, 3, k_);
#endif
  for (std::vector<cv::KeyPoint>::iterator kpt = kpts.begin(), kpt_end = kpts.end(); kpt != kpt_end; ++kpt)
  {
    cv::Mat patch = image_(cv::Rect(cvRound(kpt->pt.x) - 4, cvRound(kpt->pt.y) - 4, 9, 9));

    // Compute the response
    kpt->response = harris<uchar, int> (patch, (float)k_, dX_offsets_, dY_offsets_) * scale_sq_sq;

#if HARRIS_TEST
    cv::Mat_<float> Ix(9, 9), Iy(9, 9);

    cv::Sobel(patch, Ix, CV_32F, 1, 0, 3, scale);
    cv::Sobel(patch, Iy, CV_32F, 0, 1, 3, scale);
    float a = 0, b = 0, c = 0;
    for (unsigned int y = 1; y <= 7; ++y)
    {
      for (unsigned int x = 1; x <= 7; ++x)
      {
        a += Ix(y, x) * Ix(y, x);
        b += Iy(y, x) * Iy(y, x);
        c += Ix(y, x) * Iy(y, x);
      }
    }
    //[ a c ]
    //[ c b ]
    float response = (float)((a * b - c * c) - k_ * ((a + b) * (a + b)));

    std::cout << kpt->response << " " << response << " " << dst(kpt->pt.y,kpt->pt.x) << std::endl;
#endif
  }
}