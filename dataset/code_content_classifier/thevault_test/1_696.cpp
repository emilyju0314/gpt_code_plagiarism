void BFCLink::popAnObject(const BFCCullableHandle &handle)
	{
		AGE_ASSERT(_cullables.empty() == false);

		std::size_t i = 0;
		bool found = false;
		for (auto &e : _cullables)
		{
			if (e == handle)
			{
				found = true;
				break;
			}
			++i;
		}
		AGE_ASSERT(handle.invalid() == false);
		AGE_ASSERT(found);

		std::swap(_cullables[i], _cullables.back());
		_cullables.pop_back();
		unregisterFromTracker();
	}