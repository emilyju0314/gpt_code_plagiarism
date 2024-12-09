void
    destroy( const unsigned int& name) 
    {
        // get index into global memory
        swatches_size_type  pos = nameToIndex( name);
        // delete stop watch
        delete StopWatchC::swatches[pos];
        // invalidate storage
        StopWatchC::swatches[pos] = NULL;
    }