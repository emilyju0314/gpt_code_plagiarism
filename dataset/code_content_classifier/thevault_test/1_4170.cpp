Matrix(std::initializer_list<T> initList)
  {
    size_t m = std::min(rows * cols, size_t(initList.size()));
    auto iter = initList.begin();
    for (size_t i = 0u; i < m; ++i)
      {
        m_data[i] = T(*iter);
        ++iter;
      }

    // Zero-fill any remaining elements.
    for (size_t i = m; i < rows * cols; ++i)
      {
        m_data[i] = zero<T>();
      }
  }