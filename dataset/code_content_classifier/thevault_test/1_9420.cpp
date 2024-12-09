constexpr std::int16_t log2(std::int64_t val) noexcept
        {
            std::int16_t ret = -1;
            while (val != 0)
            {
                val >>= 1;
                ++ret;
            }
            return ret;
        }