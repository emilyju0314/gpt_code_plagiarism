int calc_target_lane(float d)
{
  int target_lane = -1;

  // Determine target vehicle's lane
  if ( d > 0 && d < 4 )
  {
    target_lane = 0; // left most lane
  }
  else if ( d > 4 && d < 8 )
  {
    target_lane = 1; // middle lane
  }
  else if ( d > 8 && d < 12 )
  {
    target_lane = 2; // right most lane
  }
  return target_lane;
}