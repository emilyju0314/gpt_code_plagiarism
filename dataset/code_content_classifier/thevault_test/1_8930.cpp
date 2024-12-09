constexpr void
    vmexit(
        syscall::bf_handle_t &handle,
        bsl::safe_u16 const &vsid,
        bsl::safe_u64 const &exit_reason) noexcept
    {
        bsl::errc_type ret{};
        constexpr bsl::safe_umx exit_reason_nmi{bsl::to_umx(0x0)};
        constexpr bsl::safe_umx exit_reason_nmi_window{bsl::to_umx(0x8)};
        constexpr bsl::safe_umx exit_reason_cpuid{bsl::to_umx(0xA)};

        /// NOTE:
        /// - At a minimum, we need to handle CPUID and NMIs on Intel. Note
        ///   that the "run" APIs all return an error code, but for the most
        ///   part we can ignore them. If the this function succeeds, it will
        ///   not return. If it fails, it will return, and the error code is
        ///   always UNKNOWN. We output the current line so that debugging
        ///   the issue is easier.
        ///

        switch (exit_reason.get()) {
            case exit_reason_nmi.get(): {
                ret = handle_vmexit_nmi(handle, vsid);
                if (bsl::unlikely(!ret)) {
                    bsl::print<bsl::V>() << bsl::here();
                    return;
                }

                bsl::discard(syscall::bf_vs_op_run_current(handle));
                bsl::print<bsl::V>() << bsl::here();
                return;
            }

            case exit_reason_nmi_window.get(): {
                ret = handle_vmexit_nmi_window(handle, vsid);
                if (bsl::unlikely(!ret)) {
                    bsl::print<bsl::V>() << bsl::here();
                    return;
                }

                bsl::discard(syscall::bf_vs_op_run_current(handle));
                bsl::print<bsl::V>() << bsl::here();
                return;
            }

            case exit_reason_cpuid.get(): {
                ret = handle_vmexit_cpuid(handle, vsid);
                if (bsl::unlikely(!ret)) {
                    bsl::print<bsl::V>() << bsl::here();
                    return;
                }

                bsl::discard(syscall::bf_vs_op_advance_ip_and_run_current(handle));
                bsl::print<bsl::V>() << bsl::here();
                return;
            }

            default: {
                break;
            }
        }

        syscall::bf_debug_op_dump_vs(vsid);

        bsl::error() << "unknown exit_reason: "    // --
                     << bsl::hex(exit_reason)      // --
                     << bsl::endl                  // --
                     << bsl::here();               // --
    }