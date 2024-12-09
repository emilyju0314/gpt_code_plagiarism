Eigen::ArrayXXf unravel(const std::vector<float> &flattenedArray,
                        const boost::optional<Eigen::ArrayXXi> &profileIndex) {
  if (profileIndex) {
    Eigen::ArrayXXf res((*profileIndex).rows(), (*profileIndex).cols());
    for (size_t row=0; row < (*profileIndex).rows(); row++)
      for (size_t col=0; col < (*profileIndex).cols(); col++)
        res(row, col) = flattenedArray[(*profileIndex)(row, col)];
    return res;
  } else {
    Eigen::ArrayXXf res(flattenedArray.size(), 1);
    for (size_t row=0; row < flattenedArray.size(); row++)
      res(row, 0) = flattenedArray[row];
    return res;
  }
}