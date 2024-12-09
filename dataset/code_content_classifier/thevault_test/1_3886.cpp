static inline void create_candidate_poses_by_limb(const size_t keypoints_number, const std::vector<cv::Mat> &pafs, const std::pair<int, int> (&limb_ids_paf)[N_PAF_LIMB_PAIRS],
                                                  const std::pair<int, int> (&limb_ids_heatmap)[N_HEATMAP_LIMB_PAIRS], const std::vector<std::vector<Peak>> &all_peaks,
                                                  const float mid_points_score_threshold, const float found_mid_points_ratio_threshold,
                                                  const std::vector<Peak> &candidates, const size_t limb_idx, std::vector<HumanPoseByPeaksIndices> &possible_poses)
{
    // A 'limb' is made up of two joints.
    // Get the heatmap indices for those two joints (the heatmaps that contain the peaks that represent those joints).
    const int idx_jointA = limb_ids_heatmap[limb_idx].first - 1;
    const int idx_jointB = limb_ids_heatmap[limb_idx].second - 1;

    // Get all the peaks (possible keypoints/joint locations) for the two joints that make up this limb
    const std::vector<Peak> &candidates_for_jointA = all_peaks[idx_jointA];
    const std::vector<Peak> &candidates_for_jointB = all_peaks[idx_jointB];

    // Get the number of joints in the two heatmaps
    const size_t njointsA = candidates_for_jointA.size();
    const size_t njointsB = candidates_for_jointB.size();

    if ((njointsA == 0) || (njointsB == 0))
    {
        maybe_create_possible_poses_from_peaks(njointsA, njointsB, possible_poses, idx_jointA, idx_jointB, candidates_for_jointA, candidates_for_jointB, keypoints_number);
    }
    else
    {
        std::vector<TwoJointsConnection> connections = form_most_promising_joint_connections(keypoints_number, pafs, limb_ids_paf, limb_idx, njointsA, njointsB, candidates_for_jointA, candidates_for_jointB, mid_points_score_threshold, found_mid_points_ratio_threshold);
        create_poses_from_connections(connections, limb_idx, possible_poses, keypoints_number, idx_jointA, idx_jointB, candidates);
    }
}