void matMaxima(const cv::Mat &mat, std::vector<Point> &locations, float rangeMin, float rangeMax) {
    assert(mat.isContinuous());
    assert(mat.channels()==1);
    assert(mat.rows > 0 && mat.cols > 1);
    assert(mat.type() == CV_8U || mat.type() == CV_32F);

    LOGTRACE3("matMaxima(%s,%f,%f)", matInfo(mat).c_str(), rangeMin, rangeMax);
    if (mat.type() == CV_8U) {
        _matMaxima<uchar>(mat, locations, (uchar)std::max(0.0f, rangeMin), (uchar)std::min(255.0f, rangeMax));
    } else if (mat.type() == CV_32F) {
        _matMaxima<float>(mat, locations, rangeMin, rangeMax);
    }
}