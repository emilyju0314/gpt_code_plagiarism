void Geometry::drawTrajectory(DrawingObject *draw, float coord0[3], float coord1[3], float radius0, float radius1, float arrowHeadSize, float scale[3], float maxLength, int segment_count, Colour* colour)
{
  float length = 0;
  Vec3d vector, pos;

  assert(coord0 && coord1);

  Vec3d start = coord0;
  Vec3d end   = coord1;

  // Obtain a vector between the two points
  vector = end - start;

  // Get centre position on vector between two coords
  pos = start + vector * 0.5;

  // Get length
  length = vector.magnitude();

  //Exceeds max length? Draw endpoint only
  if (maxLength > 0.f && length > maxLength)
  {
    //drawSphere(draw, end, radius0, segment_count);
    return;
  }

  // Draw
  if (arrowHeadSize > 0)
  {
    // Head_scale as a ratio of length [0,1] makes no sense for trajectory,
    // convert to ratio of radius (> 1) using default conversion ratio
    if (arrowHeadSize < 1.0)
      arrowHeadSize = 0.5 * arrowHeadSize / draw->radius_default; // Convert from fraction of length to multiple of radius

    // Draw final section as arrow head
    // Position so centred on end of tube adjusted for arrowhead radius (tube radius * head size)
    // Too small a section to fit arrowhead? expand so length is at least 2*r ...
    if (length < 2.0 * radius1 * arrowHeadSize)
    {
      // Adjust length
      float length_adj = arrowHeadSize * radius1 * 2.0 / length;
      vector *= length_adj;
      // Adjust to centre position
      pos = start + vector * 0.5;
    }

    // Draw the vector arrow
    drawVector(draw, pos.ref(), vector.ref(), true, 1.0, radius0, radius1, arrowHeadSize, segment_count, colour);

  }
  else
  {
    // Check segment length large enough to warrant joining points with cylinder section ...
    // Skip any section smaller than 0.3 * radius, draw sphere only for continuity
    //if (length > radius1 * 0.30)
    {
      // Join last set of points with this set
      drawVector(draw, pos, vector, true, 1.0, radius0, radius1, 0.0, segment_count, colour);
      //if (segment_count < 3 || radius1 < 1.0e-3 ) return; //Too small for spheres
      //  drawSphere(draw, pos, true, radius1, segment_count, colour);
    }
    // Finish with sphere, closes gaps in angled joins
    //Vec3d centre(coord1);
    //if (length > radius1 * 0.10)
    //  drawSphere(draw, centre, true, radius1, segment_count, colour);
  }

}