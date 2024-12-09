[[nodiscard]] static constexpr auto
    bf_page_aligned(bsl::safe_umx const &addr) noexcept -> bsl::safe_umx
    {
        bsl::expects(addr.is_valid_and_checked());
        return (addr & ~(HYPERVISOR_PAGE_SIZE - bsl::safe_u64::magic_1()));
    }