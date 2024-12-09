Product_Chebyshev_Legendre(unsigned sn_order, unsigned azimuthal_order)
      : Octant_Quadrature(sn_order), azimuthal_order_(azimuthal_order) {
    Require(sn_order > 0 && sn_order % 2 == 0);
    Require(azimuthal_order > 0 && azimuthal_order % 2 == 0);
    Ensure(this->azimuthal_order() == azimuthal_order);
  }