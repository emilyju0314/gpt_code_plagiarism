void propagate_skylight(world* out)
{
	// For each vertical strip of land, start with a lighting value of 15. Go
	// downwards, if the block is permeable to light, stay at light level 15. 
	// If not, set everything below it to 0. Add all X and Z neighbors to the 
	// queue.

	for (int x = 0; x < out->x_res; x++)
	{
		for (int z = 0; z < out->z_res; z++)
		{
			unsigned char natural = 15;

			for (int y = 0; y < out->y_res; y++)
			{
				out->set_natural(x, y, z, natural);

				if (is_not_permeable_light(out->get_id(x, y, z)))
				{
					natural = 0;
				}
			}
		}
	}

	// All blocks that are of light level 0 that have one or more neighbors 
	// that have a light level of 15 are added to the light_queue.

	std::vector<std::tuple<unsigned int, unsigned int, unsigned int>> light_queue;

	for (unsigned int x = 0; x < out->x_res; x++)
	for (unsigned int y = 0; y < out->y_res; y++)
	for (unsigned int z = 0; z < out->z_res; z++)
	{
		if (out->get_natural(x, y, z) == 0)
		{
			if 
			(
				out->get_natural_safe(x + 1, y, z) == 15 ||
				out->get_natural_safe(x - 1, y, z) == 15 ||

				out->get_natural_safe(x, y + 1, z) == 15 ||
				out->get_natural_safe(x, y - 1, z) == 15 ||

				out->get_natural_safe(x, y, z + 1) == 15 ||
				out->get_natural_safe(x, y, z - 1) == 15
			)
			{
				out->set_natural(x, y, z, 14);

				light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x, y, z));
			}
		}
	}

	// Pop the top off of the queue. We'll call this the 'current block'. 
	// Check it's six neighbors, if any of them have a light value less than 
	// the current block's light value minus one, set that neighbors light 
	// value to the current block's light value minus one, and add that 
	// neighbor to the queue. Keep doing this until the queue is empty.

	while (light_queue.size() > 0)
	{
		int x = std::get<0>(light_queue[light_queue.size() - 1]);
		int y = std::get<1>(light_queue[light_queue.size() - 1]);
		int z = std::get<2>(light_queue[light_queue.size() - 1]);

		light_queue.pop_back();

		unsigned char current_value = out->get_natural(x, y, z);

		// Right neighbor.

		if (out->in_bounds(x + 1, y, z) && out->get_natural(x + 1, y, z) < current_value - 1)
		{
			out->set_natural(x + 1, y, z, current_value - 1);

			light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x + 1, y, z));
		}

		// Left neighbor.

		if (out->in_bounds(x - 1, y, z) && out->get_natural(x - 1, y, z) < current_value - 1)
		{
			out->set_natural(x - 1, y, z, current_value - 1);

			light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x - 1, y, z));
		}

		// Bottom neighbor.

		if (out->in_bounds(x, y + 1, z) && out->get_natural(x, y + 1, z) < current_value - 1)
		{
			out->set_natural(x, y + 1, z, current_value - 1);

			light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x, y + 1, z));
		}

		// Top neighbor.

		if (out->in_bounds(x, y - 1, z) && out->get_natural(x, y - 1, z) < current_value - 1)
		{
			out->set_natural(x, y - 1, z, current_value - 1);

			light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x, y - 1, z));
		}

		// Front neighbor.

		if (out->in_bounds(x, y, z + 1) && out->get_natural(x, y, z + 1) < current_value - 1)
		{
			out->set_natural(x, y, z + 1, current_value - 1);

			light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x, y, z + 1));
		}

		// Back neighbor.

		if (out->in_bounds(x, y, z - 1) && out->get_natural(x, y, z - 1) < current_value - 1)
		{
			out->set_natural(x, y, z - 1, current_value - 1);

			light_queue.push_back(std::tuple<unsigned int, unsigned int, unsigned int>(x, y, z - 1));
		}
	}
}