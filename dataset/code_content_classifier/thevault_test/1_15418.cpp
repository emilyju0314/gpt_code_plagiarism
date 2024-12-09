void UserSet::dump(char* buffer) {
    setPinned(true);
    vector<PageIteratorPtr>* iterators = this->getIterators();
    int numIterators = iterators->size();
    int i;
    char* cur = buffer;
    for (i = 0; i < numIterators; i++) {
        PageIteratorPtr curIter = iterators->at(i);
        while (curIter->hasNext()) {
            PDBPagePtr curPage = curIter->next();
            if (curPage != nullptr) {
                memcpy(cur, curPage->getRawBytes(), curPage->getRawSize());
                cur = cur + curPage->getRawSize();
                curPage->decRefCount();
            }
        }
    }
    setPinned(false);
    delete iterators;
}