int parallel_sum(iter first, iter last, int num_parts)
{
    parallel_executor exec;
    typedef hpx::parallel::executor_traits<parallel_executor> traits;

    std::vector<boost::iterator_range<iter> > input =
        split(first, last, num_parts);

    std::vector<hpx::future<int> > v =
        traits::bulk_async_execute(exec,
            [](boost::iterator_range<iter> const& rng) -> int
            {
                return std::accumulate(boost::begin(rng), boost::end(rng), 0);
            },
            input);

    return std::accumulate(
        boost::begin(v), boost::end(v), 0,
        [](int a, hpx::future<int>& b) -> int
        {
            return a + b.get();
        });
}