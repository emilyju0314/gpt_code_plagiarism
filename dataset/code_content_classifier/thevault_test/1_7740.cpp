void LocationApiService::suspendAllTrackingSessions() {
    for (auto client : mClients) {
        // stop session if running
        if (client.second && client.second->mTracking) {
            client.second->stopTracking();
            client.second->mPendingMessages.push(E_LOCAPI_STOP_TRACKING_MSG_ID);
            LOC_LOGi("--> suspended");
        }
    }
}