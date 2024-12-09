void JSString::resolveRope(ExecState* exec) const
{
    ASSERT(isRope());

    // Allocate the buffer to hold the final string, position initially points to the end.
    UChar* buffer;
    if (PassRefPtr<UStringImpl> newImpl = UStringImpl::tryCreateUninitialized(m_length, buffer))
        m_value = newImpl;
    else {
        for (unsigned i = 0; i < m_fiberCount; ++i) {
            RopeImpl::deref(m_other.m_fibers[i]);
            m_other.m_fibers[i] = 0;
        }
        m_fiberCount = 0;
        ASSERT(!isRope());
        ASSERT(m_value == UString());
        throwOutOfMemoryError(exec);
        return;
    }
    UChar* position = buffer + m_length;

    // Start with the current RopeImpl.
    Vector<RopeImpl::Fiber, 32> workQueue;
    RopeImpl::Fiber currentFiber;
    for (unsigned i = 0; i < (m_fiberCount - 1); ++i)
        workQueue.append(m_other.m_fibers[i]);
    currentFiber = m_other.m_fibers[m_fiberCount - 1];
    while (true) {
        if (RopeImpl::isRope(currentFiber)) {
            RopeImpl* rope = static_cast<RopeImpl*>(currentFiber);
            // Copy the contents of the current rope into the workQueue, with the last item in 'currentFiber'
            // (we will be working backwards over the rope).
            unsigned fiberCountMinusOne = rope->fiberCount() - 1;
            for (unsigned i = 0; i < fiberCountMinusOne; ++i)
                workQueue.append(rope->fibers()[i]);
            currentFiber = rope->fibers()[fiberCountMinusOne];
        } else {
            UStringImpl* string = static_cast<UStringImpl*>(currentFiber);
            unsigned length = string->length();
            position -= length;
            UStringImpl::copyChars(position, string->characters(), length);

            // Was this the last item in the work queue?
            if (workQueue.isEmpty()) {
                // Create a string from the UChar buffer, clear the rope RefPtr.
                ASSERT(buffer == position);
                for (unsigned i = 0; i < m_fiberCount; ++i) {
                    RopeImpl::deref(m_other.m_fibers[i]);
                    m_other.m_fibers[i] = 0;
                }
                m_fiberCount = 0;

                ASSERT(!isRope());
                return;
            }

            // No! - set the next item up to process.
            currentFiber = workQueue.last();
            workQueue.removeLast();
        }
    }
}