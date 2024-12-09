void clearHomingStatus(uint8_t motorId)
{
    if (bHoming[motorId])
    {
        homingStatus[motorId] = HOMING_UNDEFINED;
        bHoming[motorId] = false;
        sendTwoData("/homingStatus", motorId + MOTOR_ID_FIRST, homingStatus[motorId]);
    }
}