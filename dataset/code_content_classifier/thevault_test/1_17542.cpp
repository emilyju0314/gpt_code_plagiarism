std::vector<std::vector<float>> preprocess(
  const std::vector<std::string>& paths, int img_size,
  std::string method = "crop") {
  // update as needed!

  std::vector<std::vector<float>> outputs;
  outputs.reserve(paths.size());

  auto index = 0;
  for (const auto& path : paths) {
    auto img = cv::imread(path);
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    outputs.emplace_back();
    auto& output = outputs[index++];

    if (!method.compare("crop") || !method.compare("xilinx")) {
      // Preprocess
      int img_height = img.rows;
      int img_width = img.cols;
      float scale = 1.f;
      if (img_height < img_width)
        scale = 256.f / img_height;
      else
        scale = 256.f / img_width;
      auto new_size = cv::Size(img_width * scale, img_height * scale);
      cv::resize(img, img, new_size, cv::INTER_LINEAR);
      img = center_crop(img, img_size, img_size);

      // Copy to the vector
      auto size = img.size[0] * img.size[1] * 3;
      output.resize(size);
      uchar* arr = img.isContinuous() ? img.data : img.clone().data;
      output.assign(arr, arr + size);
    } else if (!method.compare("bilinear")) {
      // Preprocess
      img.convertTo(img, CV_32FC3, 1.0 / 255.0);
      img = center_crop(img, img.rows * 0.875, img.cols * 0.875);
      auto new_size = cv::Size(img_size, img_size);
      cv::resize(img, img, new_size, cv::INTER_LINEAR);
      img = img - 0.5;
      img = img * 2;

      // Copy to the vector
      auto size = img.size[0] * img.size[1] * 3;
      output.resize(size);
      float* arr =
        img.isContinuous() ? img.ptr<float>(0) : img.clone().ptr<float>(0);
      output.assign(arr, arr + size);
    } else {
      std::cerr << "Preprocess algo " << method << " not implemented";
      exit(0);
    }
  }
  return outputs;
}