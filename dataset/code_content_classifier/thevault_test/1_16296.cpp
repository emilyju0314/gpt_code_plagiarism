Quadrature(const char* name_,
               int degree_,
               int dim_,
               int n_points_,
               VectorOfFixVecs<DimVec<double>>* lambda_,
               double* w_)
      : name(name_),
        degree(degree_),
        dim(dim_),
        n_points(n_points_),
        lambda(lambda_),
        w(w_)
    {}