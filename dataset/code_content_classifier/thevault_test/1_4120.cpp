int ESP8266AVRISP::avrisp() {
    uint8_t data, low, high;
    uint8_t ch = getch();
    // AVRISP_DEBUG("CMD 0x%02x", ch);
    switch (ch) {
    case Cmnd_STK_GET_SYNC:
        error = 0;
        empty_reply();
        break;

    case Cmnd_STK_GET_SIGN_ON:
        if (getch() == Sync_CRC_EOP) {
            _client.print((char) Resp_STK_INSYNC);
            _client.print(F("AVR ISP")); // AVR061 says "AVR STK"?
            _client.print((char) Resp_STK_OK);
        }
        break;

    case Cmnd_STK_GET_PARAMETER:
        get_parameter(getch());
        break;

    case Cmnd_STK_SET_DEVICE:
        fill(20);
        set_parameters();
        empty_reply();
        break;

    case Cmnd_STK_SET_DEVICE_EXT:   // ignored
        fill(5);
        empty_reply();
        break;

    case Cmnd_STK_ENTER_PROGMODE:
        start_pmode();
        empty_reply();
        break;

    case Cmnd_STK_LOAD_ADDRESS:
        here = getch();
        here += 256 * getch();
        // AVRISP_DEBUG("here=0x%04x", here);
        empty_reply();
        break;

    // XXX: not implemented!
    case Cmnd_STK_PROG_FLASH:
        low = getch();
        high = getch();
        empty_reply();
        break;

    // XXX: not implemented!
    case Cmnd_STK_PROG_DATA:
        data = getch();
        empty_reply();
        break;

    case Cmnd_STK_PROG_PAGE:
        program_page();
        break;

    case Cmnd_STK_READ_PAGE:
        read_page();
        break;

    case Cmnd_STK_UNIVERSAL:
        universal();
        break;

    case Cmnd_STK_LEAVE_PROGMODE:
        error = 0;
        end_pmode();
        empty_reply();
        delay(5);
        // if (_client && _client.connected())
        _client.stop();
        // AVRISP_DEBUG("left progmode");

        break;

    case Cmnd_STK_READ_SIGN:
        read_signature();
        break;
        // expecting a command, not Sync_CRC_EOP
        // this is how we can get back in sync
    case Sync_CRC_EOP:       // 0x20, space
        error++;
        _client.print((char) Resp_STK_NOSYNC);
        break;

      // anything else we will return STK_UNKNOWN
    default:
        AVRISP_DEBUG("??!?");
        error++;
        if (Sync_CRC_EOP == getch()) {
            _client.print((char)Resp_STK_UNKNOWN);
        } else {
            _client.print((char)Resp_STK_NOSYNC);
        }
  }
}