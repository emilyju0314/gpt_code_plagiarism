vector<point_type> generate_points(size_t n, data_type a, data_type b, data_type offset = 0) {
  vector<point_type> ret(n);
  parallel_for(0, n, [&] (size_t i) {
    ret[i].x = random_hash('x'+offset, i, a, b);
    ret[i].y = random_hash('y'+offset, i, a, b);
    ret[i].w = 1; //random_hash('w', i, a, b);
    });

  return ret;
}