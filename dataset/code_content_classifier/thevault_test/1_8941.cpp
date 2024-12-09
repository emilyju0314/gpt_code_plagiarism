UAVControlPanel::UAVControlPanel(wxWindow* parent)
                : wxPanel(parent, wxID_ANY)
                , keepSending(false)
                {
                    // Creates the object that will publish on the appropriate topic (buffer of length 1)
                    publisher = rosNodeHandle.advertise<geometry_msgs::Twist > (ROS_PUBLISHING_TOPIC, 1);

                    Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(UAVControlPanel::onMouseDown), NULL, this);
                    Connect(wxEVT_LEFT_UP, wxMouseEventHandler(UAVControlPanel::onMouseUp), NULL, this);
                    Connect(wxEVT_MOTION, wxMouseEventHandler(UAVControlPanel::onMouseMove), NULL, this);

                    Connect(wxEVT_PAINT, wxPaintEventHandler(UAVControlPanel::onPaint), 0, this);


                    std::string completeImagePath = NIFTiConstants::ROS_PACKAGE_PATH + NIFTiConstants::IMAGE_FOLDER_PATH + "/CartesianScales.png";

                    // Loads the background image
                    background.LoadFile(wxString::FromAscii(completeImagePath.c_str()));

                    // Initializes the object to be published to ROS to speed 0
                    desiredMotion.linear.x = 0;
                    desiredMotion.linear.y = 0;
                    desiredMotion.linear.z = 0;

                    desiredMotion.angular.x = 0;
                    desiredMotion.angular.y = 0;
                    desiredMotion.angular.z = 0;
                }