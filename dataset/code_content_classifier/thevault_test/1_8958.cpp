void VisualizationManagerForCamera::initialize()
            {
                //                renderPanel->initialize();
                //                renderPanel->setAutoRender(false);

                // Todo Adjust these params
                renderPanel->getViewport()->setBackgroundColour(NIFTiConstants::DEFAULT_BACKGROUND_COLOR_IN_OGRE_SCENE);

                display = new rviz::CameraDisplay(DISPLAY_CAMERA_NAME, sceneMgr, frameTransformer, ros::getGlobalCallbackQueue(), threadedQueue, renderPanel->getCamera(), renderPanel->getRenderWindow(), renderPanel->getViewport());
                //display = new rviz::ImageDisplay(DISPLAY_CAMERA_NAME, sceneMgr, frameTransformer, ros::getGlobalCallbackQueue(), threadedQueue, renderPanel);

                initDisplay(display, true);

                // Benoit: it seems better if no default is provided, otherwise ROS complains if the user changes this default within a millisecond since we start listening on a topic and stop right after
                //this->setViewType(VIEW_TYPE_OMNI_CAM); 

                // The target frame never changes for the camera display, so we
                // set it just once here.
                setTargetFrame(NIFTiConstants::FIXED_FRAME_STRING);

                // Sets the transport to default or the parameter if found
                std::string transportMode;
                if (NIFTiROSUtil::getParam("imageTransportMode", transportMode))
                {
                    assert(transportMode == "raw" || transportMode == "compressed" || transportMode == "theora");
                    display->setTransport(transportMode);
                }
                else
                {
                    display->setTransport(DEFAULT_TRANSPORT_MODE);
                }

            }