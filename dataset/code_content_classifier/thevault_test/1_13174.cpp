EStatus Condition::tickNode()
	{
		try
		{
			this->setResult(mCondition() ? EStatus::SUCCESS : EStatus::FAILURE);
		}
		catch (const std::exception& e)
		{
			this->setResult(EStatus::ERROR);
		}
		return this->getResult();
	}