void PolygonObstacle::toPolygonMsg(geometry_msgs::Polygon& polygon)
{
  polygon.points.resize(vertices_.size());
  for (std::size_t i=0; i<vertices_.size(); ++i)
  {
    polygon.points[i].x = vertices_[i].x();
    polygon.points[i].y = vertices_[i].y();
    polygon.points[i].z = 0;
  }
}