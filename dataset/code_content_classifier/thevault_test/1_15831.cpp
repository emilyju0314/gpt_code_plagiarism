double find_average(double *freq_values, int length) {
    double total;
    total = sum(freq_values, length);
    return total / length;
}