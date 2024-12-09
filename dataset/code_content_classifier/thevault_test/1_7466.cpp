FLOAT_TYPE Vector4::min() {
  FLOAT_TYPE min = 1000000.0;
  
  for (int i=0;i<4;i++)
    if (_v[i]<min)
      min = _v[i];

  return min;
}