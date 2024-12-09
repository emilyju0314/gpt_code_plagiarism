static int train_clustering(
    std::istream & train_src,
    std::istream & test_src,
    size_t         rank)
{
    // Read training set
    size_t cluster_cnt;
    auto train_set = read_clustering_tset(train_src, rank, &cluster_cnt);

    lvq_t lvq(rank, cluster_cnt);

    // Train the model
    lvq.set_random();
    lvq.train_unsupervised(train_set);

    // Read test set
    auto test_set = read_clustering_tset(test_src, rank);

    // Test the model
    lvq_t::clustering_statistics stats = lvq.test_clustering(test_set);

    // Print statistics
    std::cerr << "Avg. error : " << stats.avg_error() << std::endl;

    // Print cluster representants & per-cluster average error
    for (size_t i = 0; i < cluster_cnt; ++i) {
        std::cout << lvq.get(i) << std::endl;

        std::cerr
            << "Cluster " << i << " avg. error: "
            << stats.avg_error(i) << std::endl;
    }

    return 0;
}