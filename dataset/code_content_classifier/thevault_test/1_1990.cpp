void LLVMCooperativeThreadArray::_executeComplexCta(unsigned int id)
{
	const unsigned int threads  = _contexts.size();

	const unsigned int warps   = threads / _warpSize;
	const unsigned int remains = threads % _warpSize;

	report(" warp size:        " << _warpSize);
	report(" full warps:       " << warps);
	report(" remaining threas: " << remains);
	report(" entry point:      " << _entryPoint);

	ThreadList warpList;

	unsigned int threadId = 0;

	report("Executing LLVM-CTA " << id << " (" 
		<< _functions[_nextFunction]->kernel->name << ")");

	for(unsigned int warp = 0; warp < warps; ++warp)
	{
		for(unsigned int thread = 0; thread != _warpSize; ++thread)
		{
			warpList.push_back(_initializeNewContext(threadId++, id));
		}
		
		_executeWarp(warpList.begin(), warpList.end());
		
		for(ThreadList::const_iterator context = warpList.begin();
			context != warpList.end(); ++context)
		{
			_reclaimContext(*context);
		}
		
		warpList.clear();
	}
	
	for(unsigned int thread = 0; thread != remains; ++thread)
	{
		warpList.push_back(_initializeNewContext(threadId++, id));
	}
	
	_executeWarp(warpList.begin(), warpList.end());
	
	for(ThreadList::const_iterator context = warpList.begin();
		context != warpList.end(); ++context)
	{
		_reclaimContext(*context);
	}
	
	warpList.clear();

	while(_freeContexts.size() + _reclaimedContexts.size() != threads)
	{
		report("  while( free + reclaimed contexts (" 
			<< (_freeContexts.size() + _reclaimedContexts.size()) 
			<< ") != threads (" << threads << ")");
	
		_computeNextFunction();
		
		warpList = std::move(_queuedThreads[_nextFunction]);
		
		const unsigned int threads = warpList.size();
		const unsigned int warps   = threads / _warpSize;
		const unsigned int remains = threads % _warpSize;

		report("Next sub-kernel is " << _nextFunction << " (" 
			<< _functions[_nextFunction]->kernel->name << ")");

		report(" threads:          " << threads);
		report(" full warps:       " << warps);
		report(" remaining threas: " << remains);
		
		ThreadList::const_iterator begin = warpList.begin();

		for(unsigned int warp = 0; warp != warps; ++warp)
		{
			ThreadList::const_iterator end = begin;
			std::advance(end, _warpSize);
			_executeWarp(begin, end);
			begin = end;
		}
	
		ThreadList::const_iterator end = begin;
		std::advance(end, remains);
		_executeWarp(begin, end);
		
		for(ThreadList::const_iterator context = warpList.begin();
			context != warpList.end(); ++context)
		{
			_destroyContext(*context);
		}

		warpList.clear();
	}
	
	_destroyContexts();
}