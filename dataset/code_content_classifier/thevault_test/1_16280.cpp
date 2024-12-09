DOFVectorIterator(std::vector<DOFVector<T>*>& obj, DOFIteratorType t)
      : DOFIteratorBase(dynamic_cast<DOFAdmin*>(obj[0]->getFeSpace()->getAdmin()), t),
        iteratedObject(obj)
    {
      for (size_t i = 0; i < obj.size(); i++)
        it.push_back(new VectorIterator);
    }