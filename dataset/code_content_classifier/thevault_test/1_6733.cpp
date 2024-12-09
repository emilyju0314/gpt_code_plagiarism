static inline double 
jitter (double max, int be_random_)
{
  return (be_random_ ? Random::uniform(max) : 0);
}