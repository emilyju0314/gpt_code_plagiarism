[[nodiscard]] constexpr auto
    mask_enabled_and_disabled(bsl::safe_umx const &val) noexcept -> bsl::safe_u32
    {
        constexpr bsl::safe_umx ctls_mask{bsl::to_umx(0x00000000FFFFFFFFU)};
        constexpr bsl::safe_umx ctls_shift{bsl::to_umx(32)};
        return bsl::to_u32_unsafe((val & ctls_mask) & (val >> ctls_shift));
    }