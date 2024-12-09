Uint8 *
MPEG_ring:: NextWriteBuffer( void )
{
    Uint8 *buffer;

    buffer = 0;
    if ( ring->active ) {
	//printf("Waiting for write buffer (%d available)\n", SDL_SemValue(ring->writewait));
        SDL_SemWait(ring->writewait);
	//printf("Finished waiting for write buffer\n");
	if ( ring->active ) {
            buffer = ring->write + sizeof(Uint32);
        }
    }
    return buffer;
}