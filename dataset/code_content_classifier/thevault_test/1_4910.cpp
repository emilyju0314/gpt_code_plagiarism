void CollisionDetectionSystem::reportContacts(CollisionCallback& callback, Array<ContactPair>* contactPairs,
                                              Array<ContactManifold>* manifolds, Array<ContactPoint>* contactPoints, Array<ContactPair>& lostContactPairs) {

    RP3D_PROFILE("CollisionDetectionSystem::reportContacts()", mProfiler);

    // If there are contacts
    if (contactPairs->size() + lostContactPairs.size() > 0) {

        CollisionCallback::CallbackData callbackData(contactPairs, manifolds, contactPoints, lostContactPairs, *mWorld);

        // Call the callback method to report the contacts
        callback.onContact(callbackData);
    }
}