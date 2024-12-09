void UAVControlPanel::calculateDesiredMotionForScales(wxMouseEvent& event)
                {
                    // Gets the size of the control panel
                    const wxSize panelSize = this->GetSize();

                    // Gets the position of the mouse w.r.t. the axes
                    int horizontalPositionOfClick = (event.m_x - CONTROL_WIDGET_SIZE);
                    int verticalPositionOfClick = (CONTROL_WIDGET_SIZE - event.m_y);

                    // Applies limits to the four sides (cannot go faster than max speed)
                    if (horizontalPositionOfClick > CONTROL_WIDGET_SIZE)
                        horizontalPositionOfClick = CONTROL_WIDGET_SIZE;
                    if (horizontalPositionOfClick < -CONTROL_WIDGET_SIZE)
                        horizontalPositionOfClick = -CONTROL_WIDGET_SIZE;
                    if (verticalPositionOfClick > CONTROL_WIDGET_SIZE)
                        verticalPositionOfClick = CONTROL_WIDGET_SIZE;
                    if (verticalPositionOfClick < -CONTROL_WIDGET_SIZE)
                        verticalPositionOfClick = -CONTROL_WIDGET_SIZE;

                    // Gets the distance of the click from the axes (to force the user to click along the axis)
                    int distanceFromVerticalAxis = horizontalPositionOfClick < 0 ? -horizontalPositionOfClick : horizontalPositionOfClick;
                    int distanceFromHorizontalAxis = verticalPositionOfClick < 0 ? -verticalPositionOfClick : verticalPositionOfClick;

                    // Ensures that the click was close to the scale
                    if (distanceFromVerticalAxis > ALLOWED_DISTANCE_FROM_AXIS && distanceFromHorizontalAxis > ALLOWED_DISTANCE_FROM_AXIS)
                    {
                        //printf("OUT of the limits %i %i\n", distanceFromVerticalAxis, distanceFromHorizontalAxis);
                        return;
                    }

                    // Ensure that the click was not directly in the center
                    if (distanceFromVerticalAxis <= ALLOWED_DISTANCE_FROM_AXIS && distanceFromHorizontalAxis <= ALLOWED_DISTANCE_FROM_AXIS)
                    {
                        //printf("IN the limits %i %i\n", distanceFromVerticalAxis, distanceFromHorizontalAxis);
                        return;
                    }

                    // If the click is closer to the vertical axis than to the horizontal axis
                    if (distanceFromVerticalAxis > distanceFromHorizontalAxis)
                    {
                        // Updates the object to be published with the desired motion
                        desiredMotion.linear.x = MAX_HORIZONTAL_SPEED * horizontalPositionOfClick / CONTROL_WIDGET_SIZE;
                        desiredMotion.linear.z = 0;
                        //printf("HOR %i %i %f %f\n", distanceFromVerticalAxis, distanceFromHorizontalAxis, desiredMotion.linear.x, desiredMotion.linear.z);
                    }
                    else
                    {
                        // Updates the object to be published with the desired motion
                        desiredMotion.linear.x = 0;
                        desiredMotion.linear.z = MAX_VERTICAL_SPEED * verticalPositionOfClick / CONTROL_WIDGET_SIZE;
                        //printf("VER %i %i %f %f\n", distanceFromVerticalAxis, distanceFromHorizontalAxis, desiredMotion.linear.x, desiredMotion.linear.z);
                    }

                }