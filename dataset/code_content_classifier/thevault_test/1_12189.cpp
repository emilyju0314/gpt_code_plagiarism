void FirstPersonCamera::ProcessMouseInput(int32 mouseMovementX, int32 mouseMovementY, bool leftButtonPressed, bool middleButtonPressed, bool rightButtonPressed, uint32 keyboardKeyFlags)
    {
        MCORE_UNUSED(rightButtonPressed);
        MCORE_UNUSED(middleButtonPressed);
        MCORE_UNUSED(leftButtonPressed);


        EKeyboardButtonState buttonState = (EKeyboardButtonState)keyboardKeyFlags;

        AZ::Matrix4x4 transposedViewMatrix(m_viewMatrix);
        transposedViewMatrix.Transpose();

        // get the movement direction vector based on the keyboard input
        AZ::Vector3 deltaMovement(0.0f, 0.0f, 0.0f);
        if (buttonState & FORWARD)
        {
            deltaMovement += MCore::GetForward(transposedViewMatrix);
        }
        if (buttonState & BACKWARD)
        {
            deltaMovement -= MCore::GetForward(transposedViewMatrix);
        }
        if (buttonState & RIGHT)
        {
            deltaMovement += MCore::GetRight(transposedViewMatrix);
        }
        if (buttonState & LEFT)
        {
            deltaMovement -= MCore::GetRight(transposedViewMatrix);
        }
        if (buttonState & UP)
        {
            deltaMovement += MCore::GetUp(transposedViewMatrix);
        }
        if (buttonState & DOWN)
        {
            deltaMovement -= MCore::GetUp(transposedViewMatrix);
        }

        // only move the camera when the delta movement is not the zero vector
        if (MCore::SafeLength(deltaMovement) > MCore::Math::epsilon)
        {
            m_position += deltaMovement.GetNormalized() * m_translationSpeed;
        }

        // rotate the camera
        if (buttonState & ENABLE_MOUSELOOK)
        {
            m_yaw    += mouseMovementX * m_rotationSpeed;
            m_pitch  += mouseMovementY * m_rotationSpeed;
        }
    }