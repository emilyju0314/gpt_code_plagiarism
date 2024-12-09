Box buffer_bounds(const string &buf_name, int dims) {
    Box bounds;
    for (int i = 0; i < dims; i++) {
        string dim_name = std::to_string(i);

        Expr buf_min_i = Variable::make(Int(32), buf_name + ".min." + dim_name);
        Expr buf_extent_i = Variable::make(Int(32), buf_name + ".extent." + dim_name);
        Expr buf_max_i = buf_min_i + buf_extent_i - 1;

        bounds.push_back(Interval(buf_min_i, buf_max_i));
    }
    return bounds;
}