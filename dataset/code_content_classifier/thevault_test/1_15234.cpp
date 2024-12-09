INetwork *NetworkFactory::deserializeNetwork(WisdomContainerEntry *entry)
{
    //    gLogError << __func__ << endl;
    NetworkFactory::NetworkPrivPair n = NetworkFactory::newNetwork();
    if ( !n ) {
        gLogError << __func__ << " error allocating new network" << endl;
        return NULL;
    }
    n.priv()->deserializeFrom(entry);
    return n.i();
}