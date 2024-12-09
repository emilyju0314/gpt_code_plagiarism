IProfile *ProfileFactory::deserializeProfile(WisdomContainerEntry *entry)
{
    ProfileFactory::ProfilePrivPair t = newProfile();
    if ( !t ) {
        return NULL;
    }
    t.priv()->deserializeFrom(entry);
    return t.i();
}