void GrResourceAllocator::expire(unsigned int curIndex) {
    while (!fActiveIntvls.empty() && fActiveIntvls.peekHead()->end() < curIndex) {
        Interval* temp = fActiveIntvls.popHead();
        SkASSERT(!temp->next());

        if (temp->wasAssignedSurface()) {
            sk_sp<GrSurface> surface = temp->detachSurface();

            if (temp->isRecyclable()) {
                this->recycleSurface(std::move(surface));
            }
        }

        // Add temp to the free interval list so it can be reused
        SkASSERT(!temp->wasAssignedSurface()); // it had better not have a ref on a surface
        temp->setNext(fFreeIntervalList);
        fFreeIntervalList = temp;
    }
}