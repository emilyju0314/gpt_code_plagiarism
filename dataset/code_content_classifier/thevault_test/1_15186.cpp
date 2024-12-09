int j1PathFinding::CreatePath(const iPoint& origin, const iPoint& destination)
{
	ResetPath();

	int ret = 0;
	iPoint goal = App->map->WorldToMap(destination.x, destination.y);

	if (App->map->MovementCost(goal.x, goal.y) == -1 || App->map->MovementCost(goal.x, goal.y) == 0)
	{
		ret = -1;
	}

	if (ret != -1)
	{
		iPoint curr;

		frontier.Push(App->map->WorldToMap(origin.x, origin.y), 0);

		while (frontier.Count() != 0)
		{
			if (curr == goal)
			{
				break;
			}
			if (frontier.Pop(curr))
			{
				iPoint neighbors[8];
				neighbors[0].create(curr.x + 1, curr.y + 0);
				neighbors[1].create(curr.x + 0, curr.y + 1);
				neighbors[2].create(curr.x - 1, curr.y + 0);
				neighbors[3].create(curr.x + 0, curr.y - 1);
				neighbors[4].create(curr.x + 1, curr.y + 1);
				neighbors[5].create(curr.x - 1, curr.y - 1);
				neighbors[6].create(curr.x - 1, curr.y + 1);
				neighbors[7].create(curr.x + 1, curr.y - 1);


				for (uint i = 0; i < 8; ++i)
				{
					uint Distance = neighbors[i].DistanceTo(goal);

					if (App->map->MovementCost(neighbors[i].x, neighbors[i].y) > 0)
					{
						if (breadcrumbs.find(neighbors[i]) == -1 && visited.find(neighbors[i]) == -1)
						{
							cost_so_far[neighbors[i].x][neighbors[i].y] = Distance;
							frontier.Push(neighbors[i], Distance);							
							visited.add(neighbors[i]);
							breadcrumbs.add(curr);
						}
					}
				}
			}
		}
	}

	return ret;
}