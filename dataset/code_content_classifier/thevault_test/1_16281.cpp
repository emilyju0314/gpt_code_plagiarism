DOFVectorIterator(DOFAdmin* admin,
                      std::vector<DOFVector<T>*>& obj,
                      DOFIteratorType t)
      : DOFIteratorBase(admin, t),
        iteratedObject(obj)
    {
      for (size_t i = 0; i < obj.size(); i++)
        it.push_back(new VectorIterator);
    }