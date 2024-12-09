void Computer::executeIN(const InstructionWord& instruction) {
    auto device = getDevice(instruction.field());
    if (!device->allowRead()) {
        throw RuntimeError(_lineOffset, "Device does not support read: " + std::to_string(instruction.field()));
    }
    waitDevice(device);
    int32_t address = getIndexedAddress(instruction, true);
    device->read(memory, address);
}