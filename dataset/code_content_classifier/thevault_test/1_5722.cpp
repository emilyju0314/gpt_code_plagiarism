floatBO EchoBay::Comparator::find_median(Eigen::Ref<ArrayBO> input)
{
    if (input.size() < 1)
        return std::numeric_limits<floatBO>::signaling_NaN();
    if (!(input.size() % 2))
    {
        // Find the two middle positions
        const auto i1 = input.data() + (input.size()) / 2 - 1;
        const auto i2 = input.data() + input.size() / 2;

        // Partial sort
        std::nth_element(input.data(), i1, input.data() + input.size());
        const auto e1 = *i1;
        std::nth_element(input.data(), i2, input.data() + input.size());
        const auto e2 = *i2;

        return (e1 + e2) / 2;
    }
    else
    {
        // Find median on odd arrays
        const auto median_it = input.data() + input.size() / 2;
        std::nth_element(input.data(), median_it, input.data() + input.size());
        return *median_it;
    }

    return input[input.size() / 2];
}