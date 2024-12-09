hpx::future<sub_block> transpose_phase(std::vector<block> const& A,
    std::vector<block>& B, std::uint64_t block_order, std::uint64_t b,
    std::uint64_t num_blocks, std::uint64_t num_local_blocks,
    std::uint64_t block_size, std::uint64_t tile_size)
{
    const std::uint64_t from_phase = b;
    const std::uint64_t A_offset = from_phase * block_size;

    auto phase_range = boost::irange(static_cast<std::uint64_t>(0), num_blocks);
    for (std::uint64_t phase : phase_range)
    {
        const std::uint64_t from_block = phase;
        const std::uint64_t B_offset = phase * block_size;

        hpx::future<sub_block> from =
            A[from_block].get_sub_block(A_offset, block_size);
        hpx::future<sub_block> to = B[b].get_sub_block(B_offset, block_size);

        transpose(co_await from, co_await to, block_order, tile_size);
    }

    co_return sub_block();
}