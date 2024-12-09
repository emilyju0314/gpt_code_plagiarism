vector<Query_data> generate_queries(size_t q, data_type a, data_type b) {
  vector<Query_data> ret(q);

  parallel_for (0, q, [&] (size_t i) {
    data_type x1 = random_hash('q'*'x', i*2, a, b);
    data_type y1 = random_hash('q'*'y', i*2, a, b);
    int dx = random_hash('d'*'x', i, 0, win);
    int dy = random_hash('d'*'y', i, 0, win);
    int x2 = x1+dx;
    int y2 = y1+dy;
    if (dist==0) {
      x2 = random_hash('q'*'x', i*2+1, a, b);
      y2 = random_hash('q'*'y', i*2+1, a, b);
    }
    if (x1 > x2) {
      data_type t = x1; x1 = x2; x2 = t;
    }
    if (y1 > y2) {
      data_type t = y1; y1 = y2; y2 = t;
    }
    ret[i].x1 = x1; ret[i].x2 = x2;
    ret[i].y1 = y1; ret[i].y2 = y2;
    });

  return ret;
}