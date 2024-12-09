VictimObjectOfInterestMarker::VictimObjectOfInterestMarker(const eu_nifti_env_msg_ros::ElementOfInterestMessageConstPtr& msg, Ogre::SceneManager* sceneMgr, rviz::FrameTransformer* frameTransformer, Ogre::SceneNode* parent_node)
                : ObjectOfInterestMarker(sceneMgr, frameTransformer, parent_node)
                {
                    saveOOI(msg);
                }