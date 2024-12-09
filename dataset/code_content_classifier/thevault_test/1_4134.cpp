vector<tuple_type> generate_queries(size_t q, coord a, coord b) {
  vector<tuple_type> ret(q);
  parallel_for (0, q, [&] (size_t i) {
    coord x1 = random_hash('q'*'x', i*2, a, b);
    coord y1 = random_hash('q'*'y', i*2, a, b);
  int dx = random_hash('d'*'x', i, 0, win);
  int dy = random_hash('d'*'y', i, 0, win);
    int x2 = x1+dx;
    int y2 = y1+dy;
  if (dist == 0) {
    x2 = random_hash('q'*'x', i*2+1, a, b);
    y2 = random_hash('q'*'y', i*2+1, a, b);
  }
    if (x1 > x2) {
      coord t = x1; x1 = x2; x2 = t;
    }
    if (y1 > y2) {
      coord t = y1; y1 = y2; y2 = t;
    }
    ret[i] = tuple_type(x1, y1, x2, y2);
    });

  return ret;
}