bool perspective::initialize(const data::frame &cur_frm,
                                     const std::map<int, std::pair<data::keypoint, data::keypoint>> &ref_matches_with_cur) {
            // set the current camera model
            cur_camera_ = cur_frm.camera_;
            // store the keypoints and bearings
            cur_undist_keypts_.clear();
            cur_undist_keypts_.reserve(ref_matches_with_cur.size());

            cur_bearings_.clear();

            ref_undist_keypts_.clear();
            ref_undist_keypts_.reserve(ref_matches_with_cur.size());
            ref_undist_keypt_ids.clear();
            ref_undist_keypt_ids.reserve(ref_matches_with_cur.size());
            ref_bearings_.clear();

            // align matching information
            ref_cur_matches_.clear();
            ref_cur_matches_.reserve(ref_matches_with_cur.size());

            int running_index = 0;
            for (const std::pair<int, std::pair<data::keypoint, data::keypoint>> match : ref_matches_with_cur) {
                // add points to the lists of point an bearing. We dont need all points of a frame, as only matches are taken into account
                ref_undist_keypts_.emplace_back(match.second.first.get_cv_keypoint());
                ref_undist_keypt_ids.emplace_back(match.first);
                ref_bearings_.insert(std::pair<int, Vec3_t >(running_index, match.second.first.get_bearing()));
                // same for current frame
                cur_undist_keypts_.emplace_back(match.second.second.get_cv_keypoint());
                cur_bearings_.insert(std::pair<int, Vec3_t >(running_index, match.second.second.get_bearing()));
                // lastly register as match. Since we technically inserted the points ordered, it looks strange.
                ref_cur_matches_.emplace_back(std::make_pair(running_index, running_index));

                running_index++;
            }

            // set the current camera matrix
            cur_cam_matrix_ = get_camera_matrix(cur_frm.camera_);

            // compute H and F matrices
            auto homography_solver = solve::homography_solver(ref_undist_keypts_, cur_undist_keypts_, ref_cur_matches_,
                                                              1.0);
            auto fundamental_solver = solve::fundamental_solver(ref_undist_keypts_, cur_undist_keypts_,
                                                                ref_cur_matches_, 1.0);
            std::thread thread_for_H(&solve::homography_solver::find_via_ransac, &homography_solver, num_ransac_iters_,
                                     true);
            std::thread thread_for_F(&solve::fundamental_solver::find_via_ransac, &fundamental_solver,
                                     num_ransac_iters_, true);
            thread_for_H.join();
            thread_for_F.join();

            // compute a score
            const auto score_H = homography_solver.get_best_score();
            const auto score_F = fundamental_solver.get_best_score();
            const float rel_score_H = score_H / (score_H + score_F);

            // select a case according to the score
            if (0.40 < rel_score_H && homography_solver.solution_is_valid()) {
                const Mat33_t H_ref_to_cur = homography_solver.get_best_H_21();
                const auto is_inlier_match = homography_solver.get_inlier_matches();
                return reconstruct_with_H(H_ref_to_cur, is_inlier_match);
            } else if (fundamental_solver.solution_is_valid()) {
                const Mat33_t F_ref_to_cur = fundamental_solver.get_best_F_21();
                const auto is_inlier_match = fundamental_solver.get_inlier_matches();
                return reconstruct_with_F(F_ref_to_cur, is_inlier_match);
            } else {
                return false;
            }
        }