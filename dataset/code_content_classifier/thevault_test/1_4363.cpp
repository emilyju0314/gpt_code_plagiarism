void LWRController::sendResult(TASJT::GoalHandle gh)
{
	boost::unique_lock<boost::mutex> lock(mFriClient.mMutex);
	do {
		mFriClient.mCondResult.timed_wait(lock, boost::posix_time::milliseconds(150));

		switch (mFriClient.mCMDresult) {
		// TODO: Does not seem to work correctly...
		case FRIClient::CANCELED:
			gh.setCanceled(); break;
		case FRIClient::FORCE_EXCEEDED:
		{
			gh.setCanceled(TASJT::Result(), "FORCE_EXCEEDED"); break;
		}
		case FRIClient::FAILED:
			gh.setAborted(); break;
		case FRIClient::SUCCESS:
			gh.setSucceeded(); break;
		default: break;
		}
	} while (mFriClient.mCMDresult == FRIClient::UNDEF);
    ROS_INFO_STREAM("Action finished with state: " << mFriClient.mCMDresult);
}