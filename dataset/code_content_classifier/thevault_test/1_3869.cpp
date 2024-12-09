FindPeaksBody(const std::vector<cv::Mat> &heat_maps, float min_peaks_distance, std::vector<std::vector<pose::peak::Peak>> &peaks_from_heatmap)
        : heat_maps(heat_maps), min_peaks_distance(min_peaks_distance), peaks_from_heatmap(peaks_from_heatmap)
    {
        // Nothing to do
    }