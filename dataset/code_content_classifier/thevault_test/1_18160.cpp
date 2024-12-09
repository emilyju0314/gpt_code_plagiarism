Vec3 localToWorld(const Vec3& v, const Vec3& lx, const Vec3& ly,
                  const Vec3& lz) {
  return Vec3(dot(v, Vec3(lx.x, ly.x, lz.x)), dot(v, Vec3(lx.y, ly.y, lz.y)),
              dot(v, Vec3(lx.z, ly.z, lz.z)));
}