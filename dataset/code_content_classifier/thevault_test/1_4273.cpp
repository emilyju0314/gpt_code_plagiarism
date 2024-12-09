double minimal_distance_split(vector<int>& order, vector<int>& xs, vector<int>& ys, int depth)
{
  double distance = std::numeric_limits<double>::max();
  for(int i = 0; i < order.size();++i)
  {
    for(int j = i+1; j < std::min(i+8,(int)order.size());++j)
    {
        auto d = dist(std::make_tuple(xs[order[i]],ys[order[i]]),std::make_tuple(xs[order[j]],ys[order[j]]));
        // tab(depth) << "[" << i << "," << j << "] = <("<< xs[order[i]] <<"," << ys[order[i]] << "),(" << xs[order[j]] << "," << ys[order[j]] << ")> = " << d << std::endl;
        if(distance > d)
        {
          distance = d;
        }
    }
  }
  return distance;
}