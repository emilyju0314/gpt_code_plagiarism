void MotorControlPanel::onMouseDoubleClick(wxMouseEvent& event)
                {
                    desiredMotion.linear.z = EMERGENCY_BRAKE;
                    publisherCmdVel.publish(desiredMotion);
                    desiredMotion.linear.z = 0;

                    //ROS_INFO("I published [e-brake]");
                }