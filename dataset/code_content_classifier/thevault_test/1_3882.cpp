static void iot_loop(IOTHUB_MODULE_CLIENT_LL_HANDLE client_handle)
{
    while (true)
    {
        // Pull the next message from the mailbox queue
        IotMsg msg;
        const auto timeout_ms = 50;
        bool got_a_msg = mailbox.get_with_timeout(msg, timeout_ms);
        if (got_a_msg)
        {
            // Act on the message we just got
            switch (msg.type)
            {
                case IotMsgType::STOP_IOT:
                    stop_iot_loop(client_handle);
                    // Now return to let this thread join
                    return;
                case IotMsgType::SEND_MSG:
                    send_iot_msg(client_handle, std::move(msg.msg_channel), std::move(msg.msg_body));
                    break;
                default:
                    util::log_error("IoT loop got a type of message it does not understand.");
                    break;
            }
        }

        // The whole point of making this thread is that have to service the SDK
        // via this function every ~100ish ms.
        IoTHubModuleClient_LL_DoWork(client_handle);
    }
}