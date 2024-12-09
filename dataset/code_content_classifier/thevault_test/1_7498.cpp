Vector3 Vector3::rotPtAroundAxis(FLOAT_TYPE angle, Vector3 axis) const {

  Vector3 point = *this;

  // Rotate the point around a circle centered at (0,0,0)
  // Therefore substract the projection of point at axis to get this
  Vector3 proj_point = axis*(point.dot(axis));
  Vector3 direction  = point - proj_point;
  Vector3 tmp;
  
  FLOAT_TYPE x = axis[0], y = axis[1], z = axis[2];
  
  // Calculate the sine and cosine of the angle once
  FLOAT_TYPE cosTheta = (FLOAT_TYPE)cos(angle);
  FLOAT_TYPE sinTheta = (FLOAT_TYPE)sin(angle);
      
  // Find the new x position for the new rotated point
  tmp[0]  = (cosTheta + (1 - cosTheta) * x * x)     * direction[0];
  tmp[0] += ((1 - cosTheta) * x * y - z * sinTheta) * direction[1];
  tmp[0] += ((1 - cosTheta) * x * z + y * sinTheta) * direction[2];
      
  // Find the new y position for the new rotated point
  tmp[1]  = ((1 - cosTheta) * x * y + z * sinTheta) * direction[0];
  tmp[1] += (cosTheta + (1 - cosTheta) * y * y)	* direction[1];
  tmp[1] += ((1 - cosTheta) * y * z - x * sinTheta) * direction[2];
  
  // Find the new z position for the new rotated point
  tmp[2]  = ((1 - cosTheta) * x * z - y * sinTheta) * direction[0];
  tmp[2] += ((1 - cosTheta) * y * z + x * sinTheta) * direction[1];
  tmp[2] += (cosTheta + (1 - cosTheta) * z * z)     * direction[2];

  // Put the point back to the no projectoed location
  tmp += proj_point;

  return tmp;
}