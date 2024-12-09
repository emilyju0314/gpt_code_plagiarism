void TestScene::InitAnimation(Animation *animation, Entity *eParent)
	{
		for (int i = 0; i < animation->parts.size(); i++)
		{
			Entity *entity = animation->parts[i].CreateEntity(textureSheet);
			if (entity)
			{
				animation->parts[i].entity = entity;
				Add(entity);
				entity->SetParent(eParent);
			}
		}
	}