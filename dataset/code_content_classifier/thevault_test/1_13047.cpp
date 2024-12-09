static CHUNK *memheap_newchunk()
{
	CHUNK *chunk;
	char *mem;
	
	/* allocate memory */
	mem = (char*)mem_alloc(sizeof(CHUNK)+chunksize, 1);
	if(!mem)
		return 0x0;

	/* the chunk structure is located in the begining of the chunk */
	/* init it and return the chunk */
	chunk = (CHUNK*)mem;
	chunk->memory = (char*)(chunk+1);
	chunk->current = chunk->memory;
	chunk->end = chunk->memory + chunksize;
	chunk->next = (CHUNK *)0x0;
	return chunk;
}