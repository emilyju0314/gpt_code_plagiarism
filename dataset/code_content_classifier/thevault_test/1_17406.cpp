static void expand_cluster_iter(std::vector<knn_influence_space> const& kneighbours, std::vector<int> &all_clusters,
                       std::vector<int> &current_cluster, int pos_init, int cluster, int k,
                       int &assigned, std::vector<bool> &border) {

    std::vector<expand_cluster_stack> stack;
    stack.push_back({pos_init, kneighbours[pos_init].begin()});

    while (!stack.empty()) {

        bool do_recurse = false;

        expand_cluster_stack &frame = stack.back();

        if (kneighbours[frame.pos_init].size() > (k * 2.0 / 3.0)) {
            while (frame.it != kneighbours[frame.pos_init].end()) {
                auto kidx = *frame.it;
                if (all_clusters[kidx] == -1) {
                    current_cluster.push_back(kidx);
                    all_clusters[kidx] = cluster;
                    assigned++;

                    ++frame.it;
                    // Do recursion call
                    stack.push_back({kidx, kneighbours[kidx].begin()});
                    do_recurse = true;
                    break;
                }
                else {
                    ++frame.it;
                }
            }
        } else {
            border[frame.pos_init] = true;
        }
        if (!do_recurse) {
            stack.pop_back();
        }
    }
}