void
MPEG_ring:: ReadDone( void )
{
    if ( ring->active ) {
        ring->read += ring->bufSize + sizeof(Uint32);
        ring->timestamp_read++;
        if( ring->read >= ring->end )
        {
            ring->read = ring->begin;
            ring->timestamp_read = ring->timestamps;
        }
//printf("Finished read buffer, making available for writes (%d+1 available for writes)\n", SDL_SemValue(ring->writewait));
        SDL_SemPost(ring->writewait);
    }
}