constexpr thread_schedule_hint() noexcept
          : hint(-1)
          , mode(thread_schedule_hint_mode::none)
        {
        }