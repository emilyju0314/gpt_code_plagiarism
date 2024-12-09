swatches_size_type
    nameToIndex( const unsigned int& name) 
    {

#ifdef _DEBUG
        const swatches_size_type pos = name - 1;
        if(     (pos >= StopWatchC::swatches.size()) 
            || ( NULL == StopWatchC::swatches[pos])) 
        {
            RUNTIME_EXCEPTION( "No StopWatch with the requested name exist.");
        }

        return pos;
#else 
        return name - 1;
#endif
    }