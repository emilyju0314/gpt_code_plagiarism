DOFConstIterator(DOFAdmin* admin,
                     const DOFIndexed<T>* obj,
                     DOFIteratorType t)
      : DOFIteratorBase(admin, t),
        iteratedObject(obj)
    {}