CPLErr RMFRasterBand::ReadBuffer( GByte *pabyBuf, GUInt32 nBytes ) const
{
    RMFDataset  *poGDS = reinterpret_cast<RMFDataset *>( poDS );

    CPLAssert( pabyBuf != nullptr && poGDS->fp != nullptr );

    const vsi_l_offset nOffset = VSIFTellL( poGDS->fp );

    if( VSIFReadL( pabyBuf, 1, nBytes, poGDS->fp ) < nBytes )
    {
        // XXX
        if( poGDS->eAccess == GA_Update )
        {
            return CE_Failure;
        }
        else
        {
            CPLError( CE_Failure, CPLE_FileIO,
                      "Can't read at offset %ld from input file.\n%s",
                      static_cast<long>( nOffset ), VSIStrerror( errno ) );
            return CE_Failure;
        }
    }

#ifdef CPL_MSB
    if( poGDS->eRMFType == RMFT_MTW )
    {
        if( poGDS->sHeader.nBitDepth == 16 )
        {
            for( GUInt32 i = 0; i < nBytes; i += 2 )
                CPL_SWAP16PTR( pabyBuf + i );
        }

        else if( poGDS->sHeader.nBitDepth == 32 )
        {
            for( GUInt32 i = 0; i < nBytes; i += 4 )
                CPL_SWAP32PTR( pabyBuf + i );
        }

        else if( poGDS->sHeader.nBitDepth == 64 )
        {
            for( GUInt32 i = 0; i < nBytes; i += 8 )
                CPL_SWAPDOUBLE( pabyBuf + i );
        }
    }
#endif

    return CE_None;
}