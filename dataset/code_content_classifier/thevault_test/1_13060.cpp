Vector2 Entity::GetLocalPosition(const Vector2 &worldPosition)
	{
		Vector2 returnPos;
		Graphics::PushMatrix();
		Graphics::IdentityMatrix();

		std::list<Entity*> entityChain;

		Entity *current = this;
		while (current)
		{
			entityChain.push_back(current);
			current = current->parent;
		}

		Graphics::Translate(worldPosition);

		for (std::list<Entity*>::iterator i = entityChain.begin(); i != entityChain.end(); ++i)
		{
			Graphics::Scale(1.0f/(*i)->scale);
			Graphics::Rotate(-(*i)->rotation, 0, 0, 1);
			Graphics::Translate(-(*i)->position);
		}

		returnPos = Graphics::GetMatrixPosition();

		Graphics::PopMatrix();

		return returnPos;
	}