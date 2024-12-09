static inline std::vector<TwoJointsConnection> create_temp_joint_connections(const size_t njointsA, const size_t njointsB,
                                                                             const std::vector<Peak> &candidates_for_jointA,
                                                                             const std::vector<Peak> &candidates_for_jointB,
                                                                             const std::pair<cv::Mat, cv::Mat> &score_mid,
                                                                             const std::vector<cv::Mat> &pafs, const float mid_points_score_threshold,
                                                                             const float found_mid_points_ratio_threshold)
{
    std::vector<TwoJointsConnection> temp_joint_connections;
    for (size_t i = 0; i < njointsA; i++)
    {
        for (size_t j = 0; j < njointsB; j++)
        {
            const Peak &candidateA = candidates_for_jointA[i];
            const Peak &candidateB = candidates_for_jointB[j];

            maybe_create_joint_connection(temp_joint_connections, candidateA, candidateB, score_mid, pafs, mid_points_score_threshold, found_mid_points_ratio_threshold, i, j);
        }
    }

    return temp_joint_connections;
}