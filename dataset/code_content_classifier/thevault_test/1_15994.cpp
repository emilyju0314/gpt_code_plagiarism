void ESPStepperMotorServer_RestAPI::handleHomingRequest(AsyncWebServerRequest *request)
{
    this->logDebugRequestUrl(request);

    if (!request->hasParam("id"))
    {
        request->send(400, "application/json", "{\"error\": \"Missing stepper id parameter\"}");
        return;
    }

    int stepperIndex = request->getParam("id")->value().toInt();
    ESPStepperMotorServer_StepperConfiguration *stepperConfiguration = this->_stepperMotorServer->getCurrentServerConfiguration()->getStepperConfiguration(stepperIndex);
    if (stepperConfiguration == NULL)
    {
        request->send(404, "application/json", "{\"error\": \"No stepper configuration found for given stepper id\"}");
        return;
    }

    float speedInStepsPerSecond = 0;
    if (request->hasParam("speed"))
    {
        speedInStepsPerSecond = request->getParam("speed")->value().toFloat();
        if (speedInStepsPerSecond <= 0)
        {
            request->send(400, "application/json", "{\"error\": \"Value for homing speed (in steps/second) must be larger than 0\"}");
            return;
        }
    }
    else
    {
        request->send(400, "application/json", "{\"error\": \"Missing parameter for speed (in steps/second)\"}");
        return;
    }

    float accelInStepPerSecondSquare = 0;
    if (request->hasParam("accel"))
    {
        accelInStepPerSecondSquare = request->getParam("accel")->value().toFloat();
        if (accelInStepPerSecondSquare <= 0)
        {
            request->send(400, "application/json", "{\"error\": \"Acceleration value must be larger than 0\"}");
            return;
        }
    }

    unsigned int maxSteps = 2000000000;
    if (request->hasParam("maxSteps"))
    {
        maxSteps = request->getParam("maxSteps")->value().toInt();
        if (maxSteps < 1)
        {
            request->send(400, "application/json", "{\"error\": \"Max number of steps during homing must be larger than 0\"}");
            return;
        }
    }

    ESPStepperMotorServer_PositionSwitch *switchConfig;
    signed char directionTowardHome = 1;

    signed char forcedDirectionTowardHome = 0;
    if (request->hasParam("direction"))
    {
        forcedDirectionTowardHome = request->getParam("direction")->value().toInt();
        if (forcedDirectionTowardHome != 1 && forcedDirectionTowardHome != -1)
        {
            request->send(400, "application/json", "{\"error\": \"Invalid direction value given. Allowed values are 1 and -1\"}");
            return;
        }
    }

    byte gpioPinForSwitch = 0;
    //TOOD: implement proper ISR handling for custom switch parameter if not linked to existing stepper
    if (request->hasParam("switchId"))
    {
        int switchIndex = request->getParam("switchId")->value().toInt();
        switchConfig = this->_stepperMotorServer->getCurrentServerConfiguration()->getSwitch(switchIndex);
        if (switchConfig == NULL)
        {
            request->send(400, "application/json", "{\"error\": \"No switch configuration found for given switch id\"}");
            return;
        }
        gpioPinForSwitch = switchConfig->getIoPinNumber();
        //TODO: this detection is not exactely precise, since the switch could also be a combined Begin / End switch
        if (switchConfig->isTypeBitSet(SWITCHTYPE_LIMITSWITCH_POS_BEGIN_BIT))
        {
            directionTowardHome = -1;
        }
    }
    else
    {
        //Try to find pin by looking for configured limit switches of type homing switch for selected stepper motor config
        switchConfig = this->_stepperMotorServer->getCurrentServerConfiguration()->getFirstConfiguredLimitSwitchForStepper(stepperIndex);
        if (switchConfig == NULL)
        {
            request->send(400, "application/json", "{\"error\": \"No existing limit switch configuration found the stepper with the given id\"}");
            return;
        }
        gpioPinForSwitch = switchConfig->getIoPinNumber();
        // determine direction section for the case no explicit switch ID was provided
        if (switchConfig->isTypeBitSet(SWITCHTYPE_LIMITSWITCH_POS_BEGIN_BIT))
        {
            directionTowardHome = -1;
        }
    }

    ESPStepperMotorServer_Logger::logDebugf("Received homing request for stepper with id %i and limit switch on GPIO %i. Homing speed to be set to %.2f steps per second. Max step limit set to %i\n", stepperIndex, gpioPinForSwitch, speedInStepsPerSecond, maxSteps);

    ESP_FlexyStepper *stepper = stepperConfiguration->getFlexyStepper();
    if (speedInStepsPerSecond > 0)
    {
        stepper->setSpeedInStepsPerSecond(speedInStepsPerSecond);
    }
    if (accelInStepPerSecondSquare > 0)
    {
        stepper->setAccelerationInStepsPerSecondPerSecond(accelInStepPerSecondSquare);
    }

    if (forcedDirectionTowardHome != 0)
    {
        stepper->setDirectionToHome(forcedDirectionTowardHome);
    }
    else
    {
        stepper->setDirectionToHome(directionTowardHome);
    }
    stepper->goToLimitAndSetAsHome(NULL, maxSteps);
    request->send(200, "application/json", "{\"status\": \"homing procedure started\"}");
    return;
}