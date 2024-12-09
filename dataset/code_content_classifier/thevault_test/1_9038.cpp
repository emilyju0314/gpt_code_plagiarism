inline
double fixLongitude(double periodX, double lonBase, double lon) {
    
    double diffLon = lon - lonBase;

    std::vector<double> diffLonMinusZeroPlus{std::abs(diffLon - periodX),
                                             std::abs(diffLon), 
                                             std::abs(diffLon + periodX)};

    std::vector<double>::iterator it = std::min_element(diffLonMinusZeroPlus.begin(), diffLonMinusZeroPlus.end());
    int indexMin = (int) std::distance(diffLonMinusZeroPlus.begin(), it);

    // fix the longitude
    return lon + (indexMin - 1)*periodX;
}