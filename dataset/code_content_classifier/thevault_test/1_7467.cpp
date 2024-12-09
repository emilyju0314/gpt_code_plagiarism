Vector4 Vector4::reflect(const Vector4 &ref_ax) const {
  Matrix4 m, id;
  Vector4 ax = ref_ax;

  id.id();
  ax.normalize();

  m = (2.0*(m.outer(ax,ax))-id);
  return (m*(*this));
}