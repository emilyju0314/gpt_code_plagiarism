Camera(glm::vec3 position, GLboolean onGround)
    {
        this->Position = position;
        this->WorldUp = glm::vec3(0.0f,1.0f,0.0f);
        this->Yaw = YAW;
        this->Pitch = PITCH;
        this->onGround = onGround;
        this->MovementSpeed = SPEED;
        this->MouseSensitivity = SENSITIVITY;
        // initialization of the camera reference system
        this->updateCameraVectors();
    }