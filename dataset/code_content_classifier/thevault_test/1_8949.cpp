NIFTiPoseDisplay::NIFTiPoseDisplay(const std::string& name, Ogre::SceneManager* sceneMgr, rviz::FrameTransformer* frameTransformer, ros::CallbackQueueInterface* updateQueue, ros::CallbackQueueInterface* threadQueue)
                : Display(name, sceneMgr, frameTransformer, updateQueue, threadQueue)
                , msgReceivedSinceLastClear(0)
                , sceneNode(sceneMgr->getRootSceneNode()->createChildSceneNode())
                , tf_filter_(*frameTransformer->getTFClient(), "", 10, update_nh_)
                {
                    posePolygon = sceneMgr->createManualObject("posePolygon");
                    posePolygon->setDynamic(true);
                    sceneNode->attachObject(posePolygon);

                    tf_filter_.connectInput(sub_);
                    tf_filter_.registerCallback(boost::bind(&NIFTiPoseDisplay::processMessage, this, _1));
                    frameTransformer->registerFilterForTransformStatusCheck(tf_filter_, this);
                }