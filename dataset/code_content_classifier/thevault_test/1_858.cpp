void function01(void)
{
    std::cout << "BENCHMARK 1\n";
    std::cout
        << "Accumulate the times of all the positions with 10000 elements\n";
    std::cout
        << "-----------------------------------------------------------\n";
    typedef std::less<uint64_t> compare_t;
    std::mt19937 my_rand(0);
    std::vector<uint64_t> A, B;
    const uint32_t NELEM = 10000;
    A.reserve(NELEM);
    B.reserve(NELEM);

    for (uint64_t i = 0; i < NELEM; ++i)
        A.emplace_back(i);
    std::shuffle(A.begin(), A.end(), my_rand);

    auto start = std::chrono::high_resolution_clock::now();
    for (uint64_t i = 0; i < NELEM; ++i)
    {
        B = A;
        hpx::nth_element(::hpx::execution::par, B.begin(), B.begin() + i,
            B.end(), compare_t());
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<long unsigned, std::nano> nanotime1 = end - start;
    std::cout << "hpx::parallel::nth_element :" << (nanotime1.count() / 1000000)
              << " msec\n";

    start = std::chrono::high_resolution_clock::now();
    for (uint64_t i = 0; i < NELEM; ++i)
    {
        B = A;
        std::nth_element(B.begin(), B.begin() + i, B.end(), compare_t());
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<long unsigned, std::nano> nanotime2 = end - start;
    std::cout << "std::nth_element           :" << (nanotime2.count() / 1000000)
              << " msec\n";
}