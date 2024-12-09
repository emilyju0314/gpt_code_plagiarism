vector<double> runningMedian(vector<int>& a) {
    slidingWindowMedian w;

    std::vector<double> medians;
    for (auto v : a)
    {
        w.push_back(v);
        medians.push_back(w.get_median());
    }
    return medians;
}