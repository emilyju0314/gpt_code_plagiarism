constexpr explicit thread_schedule_hint(
            std::int16_t thread_hint) noexcept
          : hint(thread_hint)
          , mode(thread_schedule_hint_mode::thread)
        {
        }