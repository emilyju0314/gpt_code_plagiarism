OrbFeatureDetector::OrbFeatureDetector(size_t n_features, ORB::CommonParams params) :
  params_(params)
{
  orb_ = ORB(n_features, params);
}