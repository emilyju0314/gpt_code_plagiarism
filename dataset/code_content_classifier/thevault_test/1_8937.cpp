void VirtualPTZViewController::updateOrientation(int currentX, int currentY)
                {
                    // Calculate distance from last position
                    int motionX = currentX - lastX;
                    int motionY = currentY - lastY;

                    // Move the camera accordingly
                    virtualPTZmsg.pan += motionX * PAN_SPEED * virtualPTZmsg.horizontalFov;
                    virtualPTZmsg.tilt += motionY * TILT_SPEED * virtualPTZmsg.horizontalFov;

                    // Ensures that the limits are not surpassed (left right are at infinity right now)
                    //if (virtualPTZmsg.pan >= MAX_LEFT)
                    //    virtualPTZmsg.pan = MAX_LEFT;
                    //else if (virtualPTZmsg.pan <= MAX_RIGHT)
                    //    virtualPTZmsg.pan = MAX_RIGHT;
                    if (virtualPTZmsg.tilt >= MAX_UP)
                        virtualPTZmsg.tilt = MAX_UP;
                    else if (virtualPTZmsg.tilt <= MAX_DOWN)
                        virtualPTZmsg.tilt = MAX_DOWN;
                }