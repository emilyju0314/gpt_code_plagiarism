inline double 
LandmarkAgent::random_timer(double max, int be_random_)
{
  return (be_random_ ? rn_->uniform(max) : 0);
}