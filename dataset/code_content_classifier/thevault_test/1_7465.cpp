FLOAT_TYPE Vector4::max() {
  FLOAT_TYPE max = -1000000.0;
  
  for (int i=0;i<4;i++)
    if (_v[i]>max)
      max = _v[i];

  return max;
}