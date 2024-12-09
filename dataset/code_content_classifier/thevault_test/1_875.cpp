HPX_FORCEINLINE std::size_t fast_mod(
        std::size_t const input, std::size_t const ceil)
    {
        return input >= ceil ? input % ceil : input;
    }