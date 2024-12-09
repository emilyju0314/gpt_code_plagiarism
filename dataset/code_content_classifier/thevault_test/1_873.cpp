constexpr thread_schedule_hint(
            thread_schedule_hint_mode mode, std::int16_t hint) noexcept
          : hint(hint)
          , mode(mode)
        {
        }