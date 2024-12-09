vsi_l_offset RMFDataset::GetFileOffset( GUInt32 iRMFOffset ) const
{
    if( sHeader.iVersion >= RMF_VERSION_HUGE )
    {
        return ((vsi_l_offset)iRMFOffset) * RMF_HUGE_OFFSET_FACTOR;
    }

    return (vsi_l_offset)iRMFOffset;
}