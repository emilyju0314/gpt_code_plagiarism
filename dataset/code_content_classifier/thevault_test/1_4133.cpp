vector<Point> generate_points(size_t n, coord a, coord b) {
  vector<Point> ret(n);

  parallel_for(0, n, [&] (size_t i) {
    ret[i].x = random_hash('x', i, a, b);
    ret[i].y = random_hash('y', i, a, b);
    ret[i].w = 1; //random_hash('w', i, a, b);
    });

  return ret;
}