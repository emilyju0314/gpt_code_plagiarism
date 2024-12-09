static inline auto transform_polygon_points(const Polygon& polygon,
                                            std::vector<Cartesian>& points)
    -> void {
  for (const auto& point : polygon.outer()) {
    const auto ecef = geodetic_2_cartesian(
        geodetic_2_radian(GeodeticDegree(point.get<0>(), point.get<1>())));
    points.emplace_back(ecef);
  }
}