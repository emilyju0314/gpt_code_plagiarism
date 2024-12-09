void Computer::executeOUT(const InstructionWord& instruction) {
    auto device = getDevice(instruction.field());
    if (!device->allowWrite()) {
        throw RuntimeError(_lineOffset, "Device does not support write: " + std::to_string(instruction.field()));
    }
    waitDevice(device);
    int32_t address = getIndexedAddress(instruction, true);
    device->write(memory, address);
}