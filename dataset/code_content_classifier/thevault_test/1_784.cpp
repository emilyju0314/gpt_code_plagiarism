HarrisResponse::HarrisResponse(const cv::Mat& image, double k) :
  image_(image), k_(k)
{
  // Compute the offsets for the Harris corners once and for all
  dX_offsets_.resize(7 * 9);
  dY_offsets_.resize(7 * 9);
  std::vector<int>::iterator dX_offsets = dX_offsets_.begin(), dY_offsets = dY_offsets_.begin();
  unsigned int image_step = (unsigned int)image.step1();
  for (size_t y = 0; y <= 6 * image_step; y += image_step)
  {
    int dX_offset = y + 2, dY_offset = y + 2 * image_step;
    for (size_t x = 0; x <= 6; ++x)
    {
      *(dX_offsets++) = dX_offset++;
      *(dY_offsets++) = dY_offset++;
    }
    for (size_t x = 7; x <= 8; ++x)
      *(dY_offsets++) = dY_offset++;
  }

  for (size_t y = 7 * image_step; y <= 8 * image_step; y += image_step)
  {
    int dX_offset = y + 2;
    for (size_t x = 0; x <= 6; ++x)
      *(dX_offsets++) = dX_offset++;
  }
}