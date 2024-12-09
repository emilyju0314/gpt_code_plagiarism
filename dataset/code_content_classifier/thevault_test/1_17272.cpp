world* allocate_world(unsigned int x_res, unsigned int y_res, unsigned int z_res)
{
	world* new_world = new world();

	new_world->voxels = (voxel*)malloc(x_res * y_res * z_res * sizeof(voxel));

	if (!new_world->voxels)
	{
		std::cout << "Could not allocate enough memory for a new world." << std::endl;

		exit(13);
	}

	memset(new_world->voxels, 0, x_res * y_res * z_res * sizeof(voxel));

	new_world->x_res = x_res;
	new_world->y_res = y_res;
	new_world->z_res = z_res;

	return new_world;
}