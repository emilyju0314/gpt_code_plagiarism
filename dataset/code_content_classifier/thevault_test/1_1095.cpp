int Mqtt_Helper::Publish(char *data, String topic, String message, int maxlen=255) {

    // estimate length of packet
    int packet_length = 2 + 1*2 + topic.length() + message.length();

    if (packet_length > maxlen) {
        // available length is not sufficient
        return -1;
    }

    // publish header
    *data = 0x30;
    data++;

    // check remaining length with protocol
    packet_length = packet_length - 2;
    if (packet_length > 0xFF) {
        // remaining length does not fit
        return -1;
    }

    // remaining length
    *data = packet_length & 0xFF;
    data++;

    // topic length
    if (topic.length() > 0xFFFF) {
        // topic too long
        return -1;
    }

    uint16_t topic_length = topic.length();
    *data = topic_length & 0xFF00;
    data++;
    *data = topic_length & 0xFF;
    data++;

    // topic
    for (int i = 0; i < topic.length(); i++) {
        *data = topic[i];
        data++;
    }

    // message
    for (int i = 0; i < message.length(); i++) {
        *data = message[i];
        data++;
    }

    // no errors
    return packet_length+2;
}