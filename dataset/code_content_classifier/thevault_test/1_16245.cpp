DOFVectorDOF(const FiniteElemSpace* feSpace_, std::string name_)
      : DOFVector<DegreeOfFreedom>(feSpace_, name_)
    {
      feSpace->getAdmin()->addDOFContainer(this);
    }