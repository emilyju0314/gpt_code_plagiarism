TEST(DenseHashMapMoveTest, EmplaceHint_SpeedComparison)
{
    static const int Elements = 1e6;
    static const int Duplicates = 5;

    std::vector<int> v(Elements * Duplicates);

    for (int i = 0; i < Elements * Duplicates; i += Duplicates)
    {
        auto r = std::rand();

        for (int j = 0; j < Duplicates; ++j)
            v[i + j] = r;
    }

    std::sort(std::begin(v), std::end(v));

    auto start = std::chrono::system_clock::now();

    {
        dense_hash_map<int, int> h;
        h.set_empty_key(-1);

        for (int i = 0; i < Elements; ++i)
            h.emplace(v[i], 0);
    }

    auto end = std::chrono::system_clock::now();
    auto emplace_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    start = std::chrono::system_clock::now();

    {
        dense_hash_map<int, int> h;
        h.set_empty_key(-1);

        auto hint = h.begin();
        for (int i = 0; i < Elements; ++i)
            hint = h.emplace_hint(hint, v[i], 0).first;
    }

    end = std::chrono::system_clock::now();
    auto emplace_hint_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    ASSERT_LE(emplace_hint_time, emplace_time);
}