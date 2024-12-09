Vec3d vectorNormalToPlane(float pos0[3], float pos1[3], float pos2[3])
{
  Vec3d vector0 = Vec3d(pos0);
  Vec3d vector1 = Vec3d(pos1);
  Vec3d vector2 = Vec3d(pos2);

  //Clear invalid components (nan/inf)
  vector0.check();
  vector1.check();
  vector2.check();

  vector1 -= vector0;
  vector2 -= vector0;

  return vector1.cross(vector2);
}