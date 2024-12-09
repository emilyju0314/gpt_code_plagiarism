void KDTree::n_nearest_around_point(int idxin, int correltime, int nn,
				     KDTreeResultVector& result) {
  std::vector<float> qv(dim);  //  query vector

  result.clear(); 

  for (int i=0; i<dim; i++) {
    qv[i] = the_data[idxin][i]; 
  }
  // copy the query vector.
  
  {
    SearchRecord sr(qv, *this, result);
    // construct the search record.
    sr.centeridx = idxin;
    sr.correltime = correltime;
    sr.nn = nn; 
    root->search(sr); 
  }

  if (sort_results) sort(result.begin(), result.end());
    
}