int Mqtt_Helper::ConnectAuthenticate(char *data, String user, String password, int maxlen=255) {

    // estimate length of packet
    int packet_length = 2 + 6*2 + 6 + 6 + user.length() + password.length();

    if (packet_length > maxlen) {
        // available length is not sufficient
        return -1;
    }

    // connect header
    *data = 0x10;
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

    // packet id length
    *data = 0x00;
    data++;
    *data = 0x06;
    data++;

    // packet id
    String packetid = "MQIsdp";
    for (int i = 0; i < packetid.length(); i++) {
        *data = packetid[i];
        data++;
    }

    // level
    *data = 0x03;
    data++;

    // flags
    *data = 0xC2;
    data++;

    // i dont know what this is
    *data = 0x00;
    data++;
    *data = 0x3C;
    data++;

    // unique id length
    // I fixed id length to 6
    *data = 0x00;
    data++;
    *data = 0x06;
    data++;

    // unique id
    for (int i = 0; i < _ID.length(); i++) {
        *data = _ID[i];
        data++;
    }

    // username length
    if (user.length() > 0xFFFF) {
        // username too long
        return -1;
    }

    uint16_t user_length = user.length();
    *data = user_length & 0xFF00;
    data++;
    *data = user_length & 0xFF;
    data++;

    // username
    for (int i = 0; i < user.length(); i++) {
        *data = user[i];
        data++;
    }

    // password length
    if (password.length() > 0xFFFF) {
        // password too long
        return -1;
    }

    uint16_t password_length = password.length();
    *data = password_length & 0xFF00;
    data++;
    *data = password_length & 0xFF;
    data++;

    // password
    for (int i = 0; i < password.length(); i++) {
        *data = password[i];
        data++;
    }

    // no errors
    return packet_length+2;
}