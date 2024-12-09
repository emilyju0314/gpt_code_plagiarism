bool RadarGroundMap::SetGround(const Latitude &lat, const Longitude &lon) {
    Distance localRadius(p_camera->LocalRadius(lat, lon));

    if(!localRadius.isValid()) {
      return false;
    }

    return SetGround(SurfacePoint(lat, lon, p_camera->LocalRadius(lat, lon)));
  }