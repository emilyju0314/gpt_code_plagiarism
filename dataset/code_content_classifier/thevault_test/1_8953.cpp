MotorControlPanel::MotorControlPanel(wxWindow* parent, ros::Publisher* robotControlButtonsPublisher)
                : wxPanel(parent, wxID_ANY)
                , robotControlButtonsPublisher(robotControlButtonsPublisher)
                , keepSending(false)
                {
                    // Creates the object that will publish on the appropriate topic (buffer of length 1)
                    publisherCmdVel = rosNodeHandle.advertise<geometry_msgs::Twist > (ROS_PUBLISHING_TOPIC, 1);

//                    Connect(wxEVT_PAINT, wxPaintEventHandler(MotorControlPanel::onPaint), 0, this);
                    this->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MotorControlPanel::onMouseLeave), NULL, this);
                    
                    std::string completeImagePath = NIFTiConstants::ROS_PACKAGE_PATH + NIFTiConstants::IMAGE_FOLDER_PATH + '/' + IMAGE_FILE_NAME;
                    wxBitmap background;

                    // Loads the background image
                    bool success = background.LoadFile(wxString::FromAscii(completeImagePath.c_str()));
                    assert(success);

                    wxStaticBitmap* sb = new wxStaticBitmap(this, -1, background);

                    sb->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MotorControlPanel::onMouseDown), NULL, this);
                    sb->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MotorControlPanel::onMouseUp), NULL, this);
                    sb->Connect(wxEVT_MOTION, wxMouseEventHandler(MotorControlPanel::onMouseMove), NULL, this);
                    sb->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MotorControlPanel::onMouseDoubleClick), NULL, this);
                    
                    
                    // Initializes the object to be published to ROS to speed 0
                    desiredMotion.linear.x = 0;
                    desiredMotion.linear.y = 0;
                    desiredMotion.linear.z = 0;

                    desiredMotion.angular.x = 0;
                    desiredMotion.angular.y = 0;
                    desiredMotion.angular.z = 0;

                    this->SetMaxSize(wxSize(2 * CONTROL_WIDGET_RADIUS, 2 * CONTROL_WIDGET_RADIUS));
                    this->SetMinSize(wxSize(2 * CONTROL_WIDGET_RADIUS, 2 * CONTROL_WIDGET_RADIUS));
                }