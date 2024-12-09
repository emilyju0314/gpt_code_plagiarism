static double m2lat(double eres, double y) {
    // Normalize y
    y *= eres * pi * 2;
    // Starting value, in radians
    double lat = pi / 2 - 2 * atan(exp(-y));
    // Max 10 iterations, it takes about 6 or 7
    for (int i = 0; i < 10; i++) {
        double es = E * sin(lat);
        double nlat = pi / 2 - 2 * atan(exp(-y) * pow((1 - es) / (1 + es), E / 2));
        if (lat == nlat) // Max 
            break; // Normal exit
        lat = nlat;
    }
    return lat * 180 / pi;  // Return the value in degrees
}