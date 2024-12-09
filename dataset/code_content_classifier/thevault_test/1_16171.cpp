static int train_classifier(
    std::istream & train_src,
    std::istream & test_src,
    size_t         rank)
{
    size_t cluster_cnt;  // cluster count

    // Read training set
    auto train_set = read_classifier_tset(train_src, rank, &cluster_cnt);

    lvq_t lvq(rank, cluster_cnt);

    // Train the model
    lvq.set_random();
    lvq.train_supervised(train_set);

    // Read test set
    auto test_set = read_classifier_tset(test_src, rank);

    // Test the model
    lvq_t::classifier_statistics stats = lvq.test_classifier(test_set);

    // Print statistics
    std::cerr << "F_1      : " << stats.F(1.0)     << std::endl;
    std::cerr << "F_0.5    : " << stats.F(0.5)     << std::endl;
    std::cerr << "F_2      : " << stats.F(2.0)     << std::endl;
    std::cerr << "Accuracy : " << stats.accuracy() << std::endl;

    // Print cluster representants
    for (size_t i = 0; i < cluster_cnt; ++i)
        std::cout << lvq.get(i) << std::endl;

    return 0;
}