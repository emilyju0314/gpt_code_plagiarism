FoWEntity* FoWManager::CreateFoWEntity(iPoint pos, bool providesVisibility)
{
	FoWEntity* entity = nullptr;

	pos = App->map->MapToWorld(pos.x, pos.y);

	entity = new FoWEntity(pos, providesVisibility);

	if (entity != nullptr) {
		fowEntities.push_back(entity);
	}

	return entity;
}