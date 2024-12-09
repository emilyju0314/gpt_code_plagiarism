static float abs_line_angle(cv::Point2f const &p1,
                     cv::Point2f const &p2)
{
    float const x_diff = std::abs(p2.x- p1.x);
    float const y_diff = std::abs(p2.y- p1.y);

    return static_cast<float>(std::atan(y_diff/x_diff) * 180.0 / CV_PI);
}