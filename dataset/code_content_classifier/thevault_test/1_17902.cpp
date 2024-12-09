void check_distance_field(const PropagationDistanceField& df, const EigenSTL::vector_Vector3d& points, int numX,
                          int numY, int numZ, bool do_negs)
{
  EigenSTL::vector_Vector3i points_ind(points.size());
  for (unsigned int i = 0; i < points.size(); ++i)
  {
    Eigen::Vector3i loc;
    df.worldToGrid(points[i].x(), points[i].y(), points[i].z(), loc.x(), loc.y(), loc.z());
    points_ind[i] = loc;
  }

  for (int x = 0; x < numX; ++x)
  {
    for (int y = 0; y < numY; ++y)
    {
      for (int z = 0; z < numZ; ++z)
      {
        double dsq = df.getCell(x, y, z).distance_square_;
        double ndsq = df.getCell(x, y, z).negative_distance_square_;
        if (dsq == 0)
        {
          bool found = false;
          for (Eigen::Vector3i& point : points_ind)
          {
            if (point.x() == x && point.y() == y && point.z() == z)
            {
              found = true;
              break;
            }
          }
          if (do_negs)
          {
            ASSERT_GT(ndsq, 0) << "Obstacle point " << x << " " << y << " " << z << " has zero negative value";
          }
          ASSERT_TRUE(found) << "Obstacle point " << x << " " << y << " " << z << " not found";
        }
      }
    }
  }
}