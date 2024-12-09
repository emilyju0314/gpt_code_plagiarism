void Computer::executeSLAX(const InstructionWord& instruction) {
    int32_t address = getIndexedAddress(instruction);
    int32_t shift = (address + 10000) % 10;
    if (shift) {
        for (int i = 1; i <= (10 - shift); ++i) {
            setAX(i, getAX(i + shift));
        }
        for (int i = 11 - shift; i <= 10; ++i) {
            setAX(i, 0);
        }
    }
}