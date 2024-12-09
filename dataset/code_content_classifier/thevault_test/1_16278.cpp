DOFIterator(DOFAdmin* admin,
                DOFIndexed<T>* obj,
                DOFIteratorType t)
      : Super(admin, t),
        iteratedObject(obj)
    {}