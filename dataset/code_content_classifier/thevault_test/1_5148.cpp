bool FooBarPlugin::stop()
{
    tsp->info(u"PID: 0x%X (%d), packets: %'d", {_pid, _pid, _count});
    return true;
}