inline std::size_t next_power_of_two(std::size_t n)
		{
			if(is_power_of_two(n)) return n;
			std::size_t ct{0};
			while(n != 0)
			{
				n = n >> 1;
				++ct;
			}
			return std::size_t{1ull >> (ct + 1)};
		}