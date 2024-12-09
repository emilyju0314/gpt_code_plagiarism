static bool CompareDeallocable(const memory::MemoryResolver::DeallocableSurface &i,
                               const memory::MemoryResolver::DeallocableSurface &j)
{
    return i.first < j.first;
}