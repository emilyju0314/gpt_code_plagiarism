void Computer::executeSTJ(const InstructionWord& instruction) {
    int address = getIndexedAddress(instruction, true);
    ComputerWord word('+', 0, 0, 0, rJ[1], rJ[2]);
    copyFromRegister5(instruction, word, &memory[address]);
}