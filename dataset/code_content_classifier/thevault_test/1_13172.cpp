Node * Root::copy()
	{
		Root* newNode = new Root();
		newNode->addChild(((this->mChild)->copy()));
		return newNode;
	}