static double lat2wm(double eres, double lat) {
    if (abs(lat) > 85.052)
        return (lat > 0) ? (0.5 / eres) : (-0.5 / eres); // pi*R or -pi*R
    return log(tan(pi / 4 * (1 + lat / 90))) / eres / 2 / pi;
}