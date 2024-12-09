inline hpx::future<bool> register_with_basename(std::string const& base_name,
        hpx::future<hpx::id_type> f, std::size_t sequence_nr = ~0U)
    {
        return f.then(
            [=](hpx::future<hpx::id_type> && f) mutable
            {
                return register_with_basename(base_name, f.get(), sequence_nr);
            });
    }