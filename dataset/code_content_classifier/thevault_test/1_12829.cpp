void on_message(Ioant::Topic received_topic, ProtoIO* message){

    if (received_topic.message_type == ProtoIO::MessageTypes::RUNSTEPPERMOTORRAW)
    {
        ULOG_DEBUG << "Stepper awake";
        RunStepperMotorRawMessage *msg = static_cast<RunStepperMotorRawMessage*>(message);
        if(msg->data.number_of_step < 1 || msg->data.number_of_step > 500) return;
        if(msg->data.delay_between_steps < 1 || msg->data.delay_between_steps > 1000) return;

        if(msg->data.step_size == RunStepperMotorRaw_StepSize_FULL_STEP)
        {
            ULOG_DEBUG << "Stepper FULL STEP";
            digitalWrite(MS1,LOW);
            digitalWrite(MS2,LOW);
        }
        else if (msg->data.step_size == RunStepperMotorRaw_StepSize_HALF_STEP)
        {
            ULOG_DEBUG << "Stepper HALF STEP";
            digitalWrite(MS1,HIGH);
            digitalWrite(MS2,LOW);
        }
        else if (msg->data.step_size == RunStepperMotorRaw_StepSize_QUARTER_STEP)
        {
            ULOG_DEBUG << "Stepper QUARTER STEP";
            digitalWrite(MS1,LOW);
            digitalWrite(MS2,HIGH);
        }
        else // default fullstep
        {
            ULOG_DEBUG << "Stepper DEFAULT FULL STEP";
            digitalWrite(MS1,LOW);
            digitalWrite(MS2,LOW);
        }

        if(msg->data.direction == RunStepperMotorRaw_Direction_CLOCKWISE)
        {
            ULOG_DEBUG << "Stepper motor CW -->";
            stepCW(msg->data.number_of_step,msg->data.delay_between_steps);
        }
        else if(msg->data.direction == RunStepperMotorRaw_Direction_COUNTER_CLOCKWISE)
        {
            ULOG_DEBUG << "Stepper motor CCW  <--";
            stepCCW(msg->data.number_of_step,msg->data.delay_between_steps);
        }
        else
            ULOG_DEBUG << "ERROR: Unknown direction for stepper motor";

        digitalWrite(MS1,LOW);
        digitalWrite(MS2,LOW);
        ULOG_DEBUG << "Stepper sleeping";
    }
}