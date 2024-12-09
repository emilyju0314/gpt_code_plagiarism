void ChunkManager::getChunkCoordinates(float x, float y, float z, int* sx, int* sy, int* sz)
{
	*sx = x == 0 ? 0 : x > 0 ? (int)x/Chunk::CHUNK_SIZE : (int)x/Chunk::CHUNK_SIZE - 1;	
	*sy = y == 0 ? 0 : y > 0 ? (int)y/Chunk::CHUNK_SIZE : (int)y/Chunk::CHUNK_SIZE - 1;	
	*sz = z == 0 ? 0 : z > 0 ? (int)z/Chunk::CHUNK_SIZE : (int)z/Chunk::CHUNK_SIZE - 1;	
}