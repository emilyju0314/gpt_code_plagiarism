explicit Matrix(T a)
  {
    size_t i = rows * cols;
    while (i--)
      {
        m_data[i] = a;
      }
  }