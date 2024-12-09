blitz::RectDomain<3> field::shift(int dim, blitz::RectDomain<3> core, int steps) {
    core.lbound()(dim) += steps;
    core.ubound()(dim) += steps;

    return core;
}