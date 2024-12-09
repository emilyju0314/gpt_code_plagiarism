explicit Tri_Chebyshev_Legendre(unsigned sn_order, unsigned const mu_axis,
                                  unsigned const eta_axis)
      : Octant_Quadrature(sn_order, mu_axis, eta_axis)

  {
    Require(sn_order > 0 && sn_order % 2 == 0);
  }