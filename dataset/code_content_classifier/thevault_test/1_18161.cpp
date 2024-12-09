Vec3 sampleCosineHemisphere(Real u, Real v, Real& pdf) {
  const Real theta = 0.5 * std::acos(1.0 - 2.0 * u);
  const Real phi = PI2 * v;
  const Real y = std::cos(theta);
  pdf = y * INV_PI;
  return Vec3(std::cos(phi) * std::sin(theta), y,
              std::sin(phi) * std::sin(theta));
}