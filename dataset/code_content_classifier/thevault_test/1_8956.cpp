void InFieldPicsManager::onNewInFieldPicMsgReceived(const EXIFReader_msgs::AnnotatedPicture* picture)
            {
                boost::mutex::scoped_lock lock(mutexNewROSMessages);

                newPictures.push(eu::nifti::misc::nifti_pics_server_util::AnnotatedPicUtil::cloneAnnotatedPicture(picture));
                conditionNewROSMessages.notify_one();
            }