void ixform(vec3f &v, vec3f &r, float *m)
{
  r.x = v.x*m[0] + v.y*m[1] + v.z*m[2];
  r.y = v.x*m[4] + v.y*m[5] + v.z*m[6];
  r.z = v.x*m[8] + v.y*m[9] + v.z*m[10];
}