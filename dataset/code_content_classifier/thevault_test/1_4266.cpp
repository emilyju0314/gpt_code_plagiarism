long solve(const vector<uint64_t>& arr)
{
    auto min_max = std::minmax_element(arr.begin(), arr.end());
    // std::cout << *min_max.second << " " << *min_max.first << std::endl;

    strategy st = strategy::normal;
    
    auto spread =  *min_max.second - *min_max.first;
    if(spread < 3) st = strategy::rle;

    auto count = recursive_solve(arr, arr.begin(), arr.end(), st);
    std::cout << count << std::endl;
    return count;
}