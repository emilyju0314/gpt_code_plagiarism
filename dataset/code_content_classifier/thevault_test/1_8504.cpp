static void mg_send_mqtt_short_command(struct mg_connection *nc, uint8_t cmd,
                                       uint16_t message_id) {
    uint16_t message_id_net = htons(message_id);
    mg_send(nc, &message_id_net, 2);
    mg_mqtt_prepend_header(nc, cmd, MG_MQTT_QOS(1), 2);
}