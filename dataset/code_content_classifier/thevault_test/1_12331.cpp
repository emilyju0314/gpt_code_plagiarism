MotionInstance* MotionInstancePool::RequestNew(Motion* motion, ActorInstance* actorInstance)
    {
        Lock();
        MotionInstance* result = RequestNewWithoutLock(motion, actorInstance);
        Unlock();

        return result;
    }