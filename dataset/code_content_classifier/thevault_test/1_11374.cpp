bool I3ShadowedPhotonRemover::IsPhotonShadowed(const I3CompressedPhoton &photon) 
{
  direction_azimuth = photon.GetDir().GetAzimuth();
  direction_zenith = photon.GetDir().GetZenith();
  dx = distance_ * sin ( direction_zenith ) * cos ( direction_azimuth );
  dy = distance_ * sin ( direction_zenith ) * cos ( direction_azimuth );
  dz = distance_ * cos ( direction_zenith );
  start_position = photon.GetPos() + I3Position(dx , dy , dz);
  bool check = false;
  I3CylinderMap::const_iterator it = cylinder_map_.begin();
  while(it != cylinder_map_.end()){
    check = it->second.DoesLineIntersect( start_position , photon.GetPos());
    if(check == true){
      return check;
    }
    it++;
  }
  return check;
}