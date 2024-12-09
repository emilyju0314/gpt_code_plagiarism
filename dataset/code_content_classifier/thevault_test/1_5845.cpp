Keep_aliver(Seconds timeout = Seconds{ 0 }) noexcept
	{
		_timeout = timeout;
		reset();
	}