void
MPEG_ring:: ReleaseThreads( void )
{
    /* Let the threads know that the ring is now inactive */
    ring->active = 0;

    if ( ring->readwait ) {
        while ( SDL_SemValue(ring->readwait) == 0 ) {
            SDL_SemPost(ring->readwait);
        }
    }
    if ( ring->writewait ) {
        while ( SDL_SemValue(ring->writewait) == 0 ) {
            SDL_SemPost(ring->writewait);
        }
    }
}