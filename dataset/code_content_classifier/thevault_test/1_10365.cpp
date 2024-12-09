void WriteNormalizedImage(const string filename, const Mat& image) {
  Mat outImage;
  normalize(image, outImage, 0, 255, NORM_MINMAX,
            CV_MAKETYPE(CV_8U, image.channels()));
  imwrite(filename, outImage);
}