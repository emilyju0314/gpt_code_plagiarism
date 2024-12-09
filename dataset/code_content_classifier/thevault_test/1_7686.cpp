int TraceReplayConfig::rescale(
    DRecordData* iorec,
    int& fd, /* out */
    unsigned long long& slack_scale, /* out */
    unsigned long long& offset, /* out */
    unsigned long long& size, /* out */
    unsigned long long& iotime) /* inout in nanosecond */
{
    int lun = (*iorec)[LUN_FIELD].i;
    map<int, LUNCfg>::iterator it;
    it = lunCfgs.find(lun);

    if(it == lunCfgs.end())
        return -1;          //The lun is not specified in the cfg file, skip this recored

    LUNCfg& cfg = (*it).second;
    LBA lba = (*iorec)["lba"].i;
    ULONG64 nblks = (*iorec)["nblks"].i;
    double usecs = (*iorec)["elapsed_usecs"].d; // read useconds in double
    //ULONG64 usecs = (ULONG64) (*iorec)["elapsed_usecs"].d;
#ifdef DEBUG
    printf("usecs=%ld,lba=%ld,nblks=%ld,start_usecs=%ld,num_usecs=%ld,lba_start=%ld,cfg.nblks=%ld\n", usecs, lba, nblks, cfg.start_usecs, cfg.num_usecs, cfg.lba_start, cfg.nblks);
#endif

    // This is the first filter, check if trace record is in the time window specified in the cfg file.
    if((usecs < cfg.start_usecs) || (usecs >= (cfg.start_usecs + cfg.num_usecs)))
        return -1;

    //This is the second filter, check if the trace record is in the LBA range specified in the cfg file.
    if((lba < cfg.lba_start) || (lba >= (cfg.lba_start + cfg.nblks)))
    {
        if(rotate_outOfRange == true)
        {
            if(lba < cfg.lba_start)
            {
                lba += cfg.lba_start;
            }
            else
            {
                lba = lba % (cfg.lba_start + cfg.nblks);
            }
        }
        else
            return -1;
    }

    fd = cfg.fd;
    // Now we know the trace record should be executed, scale it as needed
    // Always shift the start time by the config file value, so the replay starts at zero
    usecs = usecs - cfg.start_usecs;
    usecs = usecs * cfg.slack_scale;  //TODO need to change cfg file to have time_scale value
    iotime = (unsigned long long)(usecs * 1000) ; // convert to nanoseconds
    // Don't do offset scaling for now  offset = (((ULONG64) (lba * cfg.lba_scale) + cfg.lba_shift) * DISK_BLOCK_SIZE;
    offset = lba * DISK_BLOCK_SIZE;
    // Don't do size scaling for now  size = nblks * cfg.iosize_scale * DISK_BLOCK_SIZE;
    size = nblks * DISK_BLOCK_SIZE;

    if(cfg.await_reply)
        slack_scale = cfg.slack_scale;
    else
        slack_scale = -1; /* send IO requests at full speed without waiting for replies */

    return 0;
}