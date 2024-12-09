std::vector<std::vector<int8_t>> preprocess(
  const std::vector<std::string>& paths) {
  // update as needed!
  const auto height = 224;
  const auto width = 224;
  const auto channels = 3;
  std::string layout = "NHWC";
  const auto fix_scale = 1;
  const std::array mean = {123, 107, 104};

  std::vector<std::vector<int8_t>> outputs;
  outputs.reserve(paths.size());

  auto index = 0;
  for (const auto& path : paths) {
    auto img = cv::imread(path);

    cv::Mat resizedImg = cv::Mat(height, width, CV_8SC3);
    cv::resize(img, resizedImg, cv::Size(width, height));
    auto size = resizedImg.size[0] * resizedImg.size[1] * channels;
    outputs.emplace_back();
    auto& output = outputs[index];
    output.resize(size);

    if (layout == "NCHW") {
      for (int c = 0; c < channels; c++) {
        for (int h = 0; h < height; h++) {
          for (int w = 0; w < width; w++) {
            output[(c * height * width) + (h * width) + w] =
              (resizedImg.at<cv::Vec3b>(h, w)[c] - mean.at(c)) * fix_scale;
          }
        }
      }
    } else if (layout == "NHWC") {
      for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
          for (int c = 0; c < channels; c++) {
            output[h * width * channels + w * channels + c] =
              (resizedImg.at<cv::Vec3b>(h, w)[c] - mean.at(c)) * fix_scale;
          }
        }
      }
    }
    index++;
  }
  return outputs;
}