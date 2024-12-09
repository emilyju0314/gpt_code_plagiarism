Vector3 Vector3::reflect(const Vector3 &ref_ax) const {
  Matrix3 m, id;
  Vector3 ax = ref_ax;

  id.id();
  ax.normalize();

  m = (2.0*(m.outer(ax,ax))-id);
  return (m*(*this));
}