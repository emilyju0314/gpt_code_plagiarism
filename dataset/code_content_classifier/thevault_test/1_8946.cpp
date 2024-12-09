void PictureMetadataUtil::publishPose(double w, double x, double y, double z)
            {
                geometry_msgs::PoseStamped message;

                message.header.frame_id = "/map";

                // position is 0,0,0

                message.pose.orientation.w = w;
                message.pose.orientation.x = x;
                message.pose.orientation.y = y;
                message.pose.orientation.z = z;


                if (publisherIsInitialized == false)
                {
                    publisher = eu::nifti::ocu::NIFTiROSUtil::getNodeHandle()->advertise<geometry_msgs::PoseStamped > ("/PicViewer/Pose", 1);
                    publisherIsInitialized = true;
                }

                publisher.publish(message);
            }