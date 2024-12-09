constexpr void
        deallocate(void *const ptr) noexcept
        {
            lock_guard lock{m_pool_lock};

            if (bsl::unlikely(nullptr == ptr)) {
                return;
            }

            if (bsl::to_umx(ptr) < bsl::to_umx(HYPERVISOR_EXT_PAGE_POOL_ADDR)) {
                bsl::error() << "invalid ptr"    // --
                             << ptr              // --
                             << bsl::endl        // --
                             << bsl::here();

                return;
            }

            *static_cast<void **>(ptr) = m_head;
            m_head = ptr;
        }