explicit Matrix(const matrix::MatrixType type)
  {
    size_t i;

    switch (type)
      {
      case matrix::Identity:
        static_assert(rows == cols, "Can't construct identity for a non-square matrix");
        i = rows * cols;
        while (i--)
          {
            m_data[i] = (i % (rows + 1u) == 0) ? one<T>() : zero<T>();
          }
        break;
      default:
        break;
      };
  }