BasisFunction::BasisFunction(std::string name_, int dim_, int degree_)
    : name(name_),
      degree(degree_),
      dim(dim_)
  {
    nDOF = new DimVec<int>(dim, -1);
    dow = Global::getGeo(WORLD);
  }