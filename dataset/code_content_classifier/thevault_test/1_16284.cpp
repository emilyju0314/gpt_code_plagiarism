explicit MatrixBase(size_type r, size_type c, value_type value0)
      : Super(S::eval(r) * S::eval(c)),
        _rows(S::eval(r)),
        _cols(S::eval(c))
    {
      set(value0);
    }