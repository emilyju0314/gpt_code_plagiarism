FLOAT_TYPE Vector3::max() {
  if( fabs(_v[0]) > fabs(_v[1]) ){
    if( fabs(_v[2]) > fabs(_v[0])){
      return _v[2];
    } else {
      return _v[0];
    }
  } else if( fabs(_v[1]) > fabs(_v[2]) ){
    return _v[0];
  } else {
    return _v[2];
  }
  return 0.0;
}