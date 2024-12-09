static KValueRef StopTimer(const ValueList& args)
		{
			int id = args.GetInt(0);
			Poco::ScopedLock<Poco::Mutex> l(timersMutex);
			
			std::map<int, Poco::Timer*>::iterator timerIter = timers.find(id);
			std::map<int, MainThreadCaller*>::iterator callerIter = callers.find(id);
			if (timerIter != timers.end() && callerIter != callers.end())
			{
				MainThreadCaller* caller = callerIter->second;
				Poco::Timer* timer = timerIter->second;
				
				// same as stop() but safe to be called from within the Timer callback
				timer->restart(0);
				callers.erase(callerIter);
				timers.erase(timerIter);
				delete caller;
				delete timer;
				
				return Value::NewBool(true);
			}
			return Value::NewBool(false);
		}