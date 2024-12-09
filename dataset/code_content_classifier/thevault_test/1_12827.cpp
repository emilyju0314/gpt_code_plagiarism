void on_message(Ioant::Topic received_topic, ProtoIO* message){
    WLOG_DEBUG << "Message received! topic:" << received_topic.global << " message type:" << received_topic.message_type;

    if (received_topic.message_type == TemperatureMessage::GetType()){
        TemperatureMessage* message = dynamic_cast<TemperatureMessage*>(message);
        odraw.Set(ODraw::SECTION_MIDDLE, 2, String(message->data.value, 2).c_str());
    }
    else if (received_topic.message_type == HumidityMessage::GetType()){
        HumidityMessage* message = dynamic_cast<HumidityMessage*>(message);
        odraw.Set(ODraw::SECTION_MIDDLE, 3, String(message->data.value, 2).c_str());
    }
}