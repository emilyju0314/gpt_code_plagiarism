void Computer::executeSLC(const InstructionWord& instruction) {
    int32_t address = getIndexedAddress(instruction);
    int32_t shift = (address + 10000) % 10;
    if (shift) {
        auto swap = [&](int start, int stop) {
            int mid = start + (stop - start) / 2;
            for (int i = start; i < mid; ++i) {
                int oppsite = stop - 1 - (i - start);
                uint8_t temp = getAX(i);
                setAX(i, getAX(oppsite));
                setAX(oppsite, temp);
            }
        };
        swap(1, shift + 1);
        swap(shift + 1, 11);
        swap(1, 11);
    }
}