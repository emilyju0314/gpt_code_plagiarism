Block* ChunkManager::getBlock(int x, int y, int z)
{
	int sx, sy, sz, bx, by, bz;
	sx = 0; sy = 0; sz = 0;
	getChunkCoordinates(x, y, z, &sx, &sy, &sz);
	
	Chunk* chunk = getChunk(sx, sy, sz);

	int size = Chunk::CHUNK_SIZE;

	if(chunk != NULL)
	{
		bx = x - sx*size;
		by = y - sy*size;
		bz = z - sz*size;
		
		return chunk->getBlock(bx, by, bz);
	}
	return NULL;
}