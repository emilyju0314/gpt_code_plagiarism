void Session::cacheCircleCoords(int segment_count)
{
  // Recalc required? Only done first time called and when segment count changes
  if (segment_count == 0 || segments == segment_count) return;
  GLfloat angle;
  float angle_inc = 2*M_PI / (float)segment_count;
  int idx;

  // Calculate unit circle points when divided into specified segments
  // and store in static variable to re-use every time a vector with the
  // same segment count is drawn
  segments = segment_count;
  if (x_coords != NULL) delete[] x_coords;
  if (y_coords != NULL) delete[] y_coords;

  x_coords = new float[segment_count + 1];
  y_coords = new float[segment_count + 1];

  // Loop around in a circle and specify even points along the circle
  // as the vertices for the triangle fan cone, cone base and arrow shaft
  for (idx = 0; idx <= segments; idx++)
  {
    angle = angle_inc * (float)idx;
    // Calculate x and y position of the next vertex and cylinder normals (unit circle coords)
    x_coords[idx] = sin(angle);
    y_coords[idx] = cos(angle);
  }
}