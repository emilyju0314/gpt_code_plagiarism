int void_parallel_sum(iter first, iter last, int num_parts)
{
    void_parallel_executor exec;
    typedef hpx::parallel::executor_traits<void_parallel_executor> traits;

    std::vector<int> temp(num_parts + 1, 0);
    std::iota(boost::begin(temp), boost::end(temp), 0);

    std::ptrdiff_t section_size = std::distance(first, last) / num_parts;

    std::vector<hpx::future<void> > f = traits::bulk_async_execute(exec,
        [&](const int& i)
        {
            iter b = first + i*section_size; //-V104
            iter e = first + (std::min)(
                    std::distance(first, last),
                    static_cast<std::ptrdiff_t>((i+1)*section_size) //-V104
                );
            temp[i] = std::accumulate(b, e, 0); //-V108
        },
        temp);

    hpx::when_all(f).get();

    return std::accumulate(boost::begin(temp), boost::end(temp), 0);
}