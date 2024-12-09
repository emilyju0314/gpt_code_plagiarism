void Computer::executeIOC(const InstructionWord& instruction) {
    auto device = getDevice(instruction.field());
    waitDevice(device);
    if (device->type() == IODeviceType::DISK) {
        device->control(rX.value());
    } else {
        int32_t address = getIndexedAddress(instruction);
        device->control(address);
    }
}