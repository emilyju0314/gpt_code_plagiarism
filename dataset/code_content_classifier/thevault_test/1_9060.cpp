DirectionalOdometerPins(uint8_t pulsePin, uint8_t forwardWhenLowPin)
        : pulse{ pulsePin }
        , direction{ forwardWhenLowPin }
    {
    }