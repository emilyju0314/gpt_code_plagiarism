explicit MatrixBase(size_type r = 0, size_type c = 0)
      : Super(S::eval(r) * S::eval(c == 0 ? r : c)),
        _rows(S::eval(r)),
        _cols(S::eval(c == 0 ? r : c))
    {}