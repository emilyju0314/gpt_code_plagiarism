uint8 USBSerial::read(void) {
    uint8 b;
    this->read(&b, 1);
    return b;
}