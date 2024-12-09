void
MPEG_ring:: WriteDone( Uint32 len, double timestamp)
{
    if ( ring->active ) {
#ifdef NO_GRIFF_MODS
        assert(len <= ring->bufSize);
#else
	if ( len > ring->bufSize )
            len = ring->bufSize;
#endif
        *((Uint32*) ring->write) = len;

        ring->write += ring->bufSize + sizeof(Uint32);
        *(ring->timestamp_write++) = timestamp;
        if( ring->write >= ring->end )
        {
            ring->write = ring->begin;
            ring->timestamp_write = ring->timestamps;
        }
//printf("Finished write buffer of %u bytes, making available for reads (%d+1 available for reads)\n", len, SDL_SemValue(ring->readwait));
        SDL_SemPost(ring->readwait);
    }
}