void CanCommunication::validateMotorsCalibrationFromUserInput(int mode)
{
    waiting_for_user_trigger_calibration = false;
    if (mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL || mode == CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
        steppers_calibration_mode = mode;
    }
}