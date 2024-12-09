EStatus Timer::tickNode()
	{
		if (timerSet)
		{
			this->setResult(EStatus::RUNNING);
		}
		else if (mInnerResult != EStatus::RUNNING)
		{
			this->setResult(mInnerResult);
		}
		else
		{
			if (!timerSet)
			{
				std::thread timer(&Timer::setTimer, this);
				timerSet = true;
				timer.detach();
			}

			this->setResult(EStatus::RUNNING);
		}
		return this->getResult();
	}