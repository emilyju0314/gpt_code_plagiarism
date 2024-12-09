FLOAT_TYPE Vector3::min() {
  FLOAT_TYPE min = 1000000.0;

  for (int i=0;i<3;i++)
    if (_v[i]<min)
      min = _v[i];

  return min;
}