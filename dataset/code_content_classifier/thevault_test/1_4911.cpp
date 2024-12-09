void CollisionDetectionSystem::reportTriggers(EventListener& eventListener, Array<ContactPair>* contactPairs, Array<ContactPair>& lostContactPairs) {

    RP3D_PROFILE("CollisionDetectionSystem::reportTriggers()", mProfiler);

    // If there are contacts
    if (contactPairs->size() + lostContactPairs.size() > 0) {

        OverlapCallback::CallbackData callbackData(*contactPairs, lostContactPairs, true, *mWorld);

        // Call the callback method to report the overlapping shapes
        eventListener.onTrigger(callbackData);
    }
}