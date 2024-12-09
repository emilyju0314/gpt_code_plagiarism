void Computer::executeSRA(const InstructionWord& instruction) {
    int32_t address = getIndexedAddress(instruction);
    int32_t shift = (address + 10000) % 5;
    if (shift) {
        for (int i = 5; i > shift; --i) {
            rA[i] = rA[i - shift];
        }
        for (int i = shift; i > 0; --i) {
            rA[i] = 0;
        }
    }
}