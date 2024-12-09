[[nodiscard]] constexpr auto
    bf_is_page_aligned(bsl::safe_u64 const &addr) noexcept -> bool
    {
        bsl::expects(addr.is_valid_and_checked());

        constexpr auto mask{HYPERVISOR_PAGE_SIZE - bsl::safe_u64::magic_1()};
        return (addr & mask).is_zero();
    }