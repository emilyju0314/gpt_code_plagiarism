SetCachePageIterator::SetCachePageIterator(PageCachePtr cache, UserSet* set) {
    this->cache = cache;
    this->set = set;
    this->iter = this->set->getDirtyPageSet()->begin();
}