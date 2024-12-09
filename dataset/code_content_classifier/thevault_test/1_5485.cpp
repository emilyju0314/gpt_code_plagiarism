void Computer::executeMOVE(const InstructionWord& instruction) {
    int32_t originAddress = getIndexedAddress(instruction);
    int32_t targetAddress = rI1.value();
    uint8_t amount = instruction.field();
    for (uint8_t i = 0; i < amount; ++i) {
        int32_t target = targetAddress + i;
        int32_t origin = originAddress + i;
        if (target < 0 || target >= NUM_MEMORY) {
            continue;
        }
        memory[target] = memory[origin];
    }
    rI1.set(targetAddress + amount);
}