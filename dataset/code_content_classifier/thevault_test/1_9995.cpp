float TriangleGeometer::getDistanceToPoint(const Point& point) const {
  using Vector = Point;

  // Check if the point is in the region outside A
  const Vector ab = vertices_.vertex_b - vertices_.vertex_a;
  const Vector ac = vertices_.vertex_c - vertices_.vertex_a;
  const Vector ap = point - vertices_.vertex_a;
  const float d1 = ab.dot(ap);
  const float d2 = ac.dot(ap);
  if (d1 <= 0.0f && d2 <= 0.0f) {
    // The barycentric coordinates are (1,0,0) => the closest point is vertex_a
    return (vertices_.vertex_a - point).norm();
  }

  // Check if P in vertex region outside B
  const Vector bp = point - vertices_.vertex_b;
  const float d3 = ab.dot(bp);
  const float d4 = ac.dot(bp);
  if (d3 >= 0.0f && d4 <= d3) {
    // The barycentric coordinates are (0,1,0) => the closest point is vertex_b
    return (vertices_.vertex_b - point).norm();
  }

  // Check if P in edge region of AB, if so return projection of P onto AB
  const float vc = d1 * d4 - d3 * d2;
  if (vc <= 0.0f && d1 >= 0.0f && d3 <= 0.0f) {
    const float v = d1 / (d1 - d3);
    // The barycentric coordinates are (1-v,v,0)
    Point closest_pt = vertices_.vertex_a + v * ab;
    return (closest_pt - point).norm();
  }

  // Check if P in vertex region outside C
  Vector cp = point - vertices_.vertex_c;
  const float d5 = ab.dot(cp);
  const float d6 = ac.dot(cp);
  if (d6 >= 0.0f && d5 <= d6) {
    // The barycentric coordinates are (0,0,1) => the closest point is vertex_c
    return (vertices_.vertex_c - point).norm();
  }

  // Check if P in edge region of AC, if so return projection of P onto AC
  const float vb = d5 * d2 - d1 * d6;
  if (vb <= 0.0f && d2 >= 0.0f && d6 <= 0.0f) {
    const float w = d2 / (d2 - d6);
    // The barycentric coordinates are (1-w,0,w)
    const Point closest_pt = vertices_.vertex_a + w * ac;
    return (closest_pt - point).norm();
  }

  // Check if P in edge region of BC, if so return projection of P onto BC
  const float va = d3 * d6 - d5 * d4;
  if (va <= 0.0f && (d4 - d3) >= 0.0f && (d5 - d6) >= 0.0f) {
    const float w = (d4 - d3) / ((d4 - d3) + (d5 - d6));
    // The barycentric coordinates are (0,1-w,w)
    const Point closest_pt =
        vertices_.vertex_b + w * (vertices_.vertex_c - vertices_.vertex_b);
    return (closest_pt - point).norm();
  }

  // P inside face region. Compute Q through its barycentric coordinates (u,v,w)
  const float denom = 1.0f / (va + vb + vc);
  const float v = vb * denom;
  const float w = vc * denom;
  // = u*a + v*b + w*c, u = va * denom = 1.0f - v - w
  const Point closest_pt = vertices_.vertex_a + ab * v + ac * w;
  return (closest_pt - point).norm();
}