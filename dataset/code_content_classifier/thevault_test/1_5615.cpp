Uint32
MPEG_ring:: NextReadBuffer( Uint8** buffer )
{
    Uint32 size;

    size = 0;
    if ( ring->active ) {
        /* Wait for a buffer to become available */
//printf("Waiting for read buffer (%d available)\n", SDL_SemValue(ring->readwait));
        SDL_SemWait(ring->readwait);
//printf("Finished waiting for read buffer\n");
	if ( ring->active ) {
            size = *((Uint32*) ring->read);
            *buffer = ring->read + sizeof(Uint32);
        }
    }
    return size;
}