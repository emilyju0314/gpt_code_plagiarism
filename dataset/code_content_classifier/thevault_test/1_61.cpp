void updateFlatData(std::vector<float> & flatArray, const Eigen::ArrayXXf &array,
                    const boost::optional<Eigen::ArrayXXi> &profileIndex) {
  if (profileIndex) {
    for (size_t row=0; row < (*profileIndex).rows(); row++)
      for (size_t col=0; col < (*profileIndex).cols(); col++)
        flatArray[(*profileIndex)(row, col)] = array(row, col);
  } else {
    ASSERT(array.cols() == 1);
    for (size_t row=0; row < array.rows(); row++)
      flatArray[row] = array(row, 0);
  }
}