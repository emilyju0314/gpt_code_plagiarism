void ble_evt_attclient_find_information_found (
    const struct ble_msg_attclient_find_information_found_evt_t *msg)
{
    if (GanglionLib::state == GanglionLib::State::OPEN_CALLED)
    {
        if ((GanglionLib::ganglion_handle_recv) && msg->uuid.len == 2)
        {
            uint16 uuid = (msg->uuid.data[1] << 8) | msg->uuid.data[0];
            if (uuid == CLIENT_CHARACTERISTIC_UUID)
            {
                GanglionLib::client_char_handle = msg->chrhandle;
            }
        }
        if (msg->uuid.len == 16)
        {
            bool is_send = true;
            bool is_recv = true;
            for (int i = 0; i < 16; i++)
            {
                if (msg->uuid.data[i] != GanglionLib::send_char_uuid_bytes[i])
                {
                    is_send = false;
                }
                if (msg->uuid.data[i] != GanglionLib::recv_char_uuid_bytes[i])
                {
                    is_recv = false;
                }
            }
            if (is_recv)
            {
                GanglionLib::ganglion_handle_recv = msg->chrhandle;
            }
            if (is_send)
            {
                GanglionLib::ganglion_handle_send = msg->chrhandle;
            }
        }
        if ((GanglionLib::ganglion_handle_send) && (GanglionLib::ganglion_handle_recv) &&
            (GanglionLib::client_char_handle) &&
            (GanglionLib::state == GanglionLib::State::OPEN_CALLED))
        {
            GanglionLib::exit_code = (int)GanglionLib::STATUS_OK;
        }
    }
}