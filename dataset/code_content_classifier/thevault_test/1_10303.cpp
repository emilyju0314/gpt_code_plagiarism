void add_matrix_to_vectors(const Matrix &block, std::vector<double> &V,
                           std::vector<int> &I, std::vector<int> &J,
                           int vert_offset, int horiz_offset) {
  auto number_of_nonzeros = block.nonZeros();
  V.reserve(V.size() + number_of_nonzeros);
  I.reserve(I.size() + number_of_nonzeros);
  J.reserve(J.size() + number_of_nonzeros);

  for (int k = 0; k < block.outerSize(); ++k) {
    for (Matrix::InnerIterator it(block, k); it; ++it) {
      V.push_back(it.value());

      /* Push back current row and column indices */
      I.push_back(it.row() + vert_offset);
      J.push_back(it.col() + horiz_offset);
    }
  }
}