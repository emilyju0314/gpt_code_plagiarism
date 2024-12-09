void function02(void)
{
    std::cout << "\nBENCHMARK 2\n";
    std::cout << "Times with different positionss with 10000000 elements\n";
    std::cout << "-------------------------------------------------\n";
    typedef std::less<uint64_t> compare_t;
    std::mt19937 my_rand(0);
    std::vector<uint64_t> A, B;
    const uint32_t NELEM = 10000000;
    A.reserve(NELEM);
    B.reserve(NELEM);

    for (uint64_t i = 0; i < NELEM; ++i)
        A.emplace_back(i);
    std::shuffle(A.begin(), A.end(), my_rand);

    uint64_t ac1 = 0, ac2 = 0;
    const uint32_t STEP = NELEM / 20;
    for (uint64_t i = 0; i < NELEM; i += STEP)
    {
        std::cout << "Searched position [" << i << "]   \t";

        B = A;
        auto start = std::chrono::high_resolution_clock::now();
        hpx::nth_element(::hpx::execution::seq, B.begin(), B.begin() + i,
            B.end(), compare_t());
        //hpx::nth_element (B.begin(), B.begin() + i, B.end(),compare_t());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long unsigned, std::nano> nanotime1 = end - start;
        ac1 += nanotime1.count();
        std::cout << "hpx::parallel::nth_element :"
                  << (nanotime1.count() / 1000000) << " msec";
        HPX_ASSERT(B[i] == i);

        B = A;
        start = std::chrono::high_resolution_clock::now();
        std::nth_element(B.begin(), B.begin() + i, B.end(), compare_t());
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<long unsigned, std::nano> nanotime2 = end - start;
        ac2 += nanotime2.count();
        std::cout << "  \tstd::nth_element       :"
                  << (nanotime2.count() / 1000000) << " msec\n";
        HPX_ASSERT(B[i] == i);
    }
    std::cout << "\n\n";
    std::cout << "Accumulated (msec) hpx::parallel::nth_element "
              << ac1 / 1000000 << " msec\n";
    std::cout << "Accumulated (msec) std::nth_element           "
              << ac2 / 1000000 << " msec\n";
}