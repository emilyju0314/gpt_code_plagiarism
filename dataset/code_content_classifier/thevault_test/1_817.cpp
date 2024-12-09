static void benchmark_sampling_methods(benchmark::State& state)
{

    const ISCAS85File file_id = static_cast<ISCAS85File>(state.range(2));
    const std::string file = iscas_85_filename_by_id(file_id);

    std::string sampling_name;
    switch (state.range(0))
    {
    case REGULAR: sampling_name = "regular sampling"; break;
    case IMPROVED: sampling_name = "improved sampling"; break;
    }
    state.SetLabel(file + " - " + sampling_name + ": " + std::to_string(state.range(1)));

    Cudd mgr(0);
    std::vector<BDD> original = load_iscas_85_file(mgr, file_id);

    std::vector<BDD> rounded;
    rounded.reserve(original.size());
    for (std::size_t i = 0; i < original.size(); i++)
    {
        rounded.push_back(mgr.bddZero());
    }

    for (auto _ : state)
    {
        switch (state.range(0))
        {
        case REGULAR:
            abo::error_metrics::error_rate_sampling(mgr, original, rounded, state.range(1));
            break;
        case IMPROVED:
            abo::error_metrics::error_rate_efficient_sampling(mgr, original, rounded,
                                                              state.range(1));
            break;
        }

        state.PauseTiming();
        mgr.CollectGarbage();
        state.ResumeTiming();
    }
}