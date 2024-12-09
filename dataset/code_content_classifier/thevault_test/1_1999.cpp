void BankChecker::
access( unsigned int tidx, unsigned int tidy, unsigned int tidz,
        unsigned int bdimx, unsigned int bdimy, unsigned int bdimz,
        const char* file, const int line, const std::string& aname,
        const int index)
{ 
    is_active = true;

    // linearized thread id
    unsigned int ltid = getLtid( tidx, tidy, tidz, bdimx, bdimy, bdimz);

    // reset state if new warp
    if( 0 == (ltid & (warp_size - 1))) 
    {
        // double check to handle multiple shared mem accesses in one line
        if( last_ltid != 0) 
        {
            reset();
        }
    }

    AccessLocation loc( file, line, aname, ltid);
    AccessInfo info( ltid, tidx, tidy, tidz, index);
    access_data[loc][(index % warp_size)].push_back( info);

    if( 15 == (ltid & (warp_size - 1))) 
    {
        analyse( access_data. find( loc));
    }

    last_ltid = (ltid % warp_size);
}