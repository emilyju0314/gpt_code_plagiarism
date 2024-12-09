TEST(generate, ExampleOne) {
    const auto randomNumber = []()->double{
        return std::rand();
    };
    std::vector<double> v(5);
    std::generate(v.begin(), v.end(), randomNumber);
}