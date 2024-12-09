void Computer::executeSRAX(const InstructionWord& instruction) {
    int32_t address = getIndexedAddress(instruction);
    int32_t shift = (address + 10000) % 10;
    if (shift) {
        for (int i = 10; i > shift; --i) {
            setAX(i, getAX(i - shift));
        }
        for (int i = shift; i > 0; --i) {
            setAX(i, 0);
        }
    }
}