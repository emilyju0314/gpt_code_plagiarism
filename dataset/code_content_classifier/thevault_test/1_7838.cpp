float DistanceFunction::compute_distance(struct Rect * query, struct Rect * item) {
  // if NULL == query, then use the query points queue,
  // else use query.
  float distance = 0, d=0.0;
  // since here we assume we're dealing with points, we're
  // using only the first NUMDIMS dimensions, as the others
  // are repetitions.
  if (NULL == query) { // its a fixed (multipoint) query
    assert(total_point_wt_sum > 0.0); // used to normalize ->/0
    // iterate over points
    for (multimap<float,struct Rect,less<float> >:: iterator it = query_point_queue.begin();
         it != query_point_queue.end(); it++) { // add up each point
      d = compute_distance_aux( &(*it).second, item);
      distance += d * ((*it).first/total_point_wt_sum); // wsum, normalized by total
    }
  } else { // its a simple, joinable query.
    distance = compute_distance_aux(query,item);
  }
  return distance;
}