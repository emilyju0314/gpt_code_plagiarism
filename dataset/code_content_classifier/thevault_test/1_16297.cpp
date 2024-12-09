FastQuadrature(BasisFunction* basFcts, Quadrature* quad, Flag flag)
      : init_flag(flag),
        phi(0, 0),
        D2Phi(NULL),
        quadrature(quad),
        basisFunctions(basFcts)
    {}