void Computer::executeSTi(const InstructionWord& instruction) {
    int address = getIndexedAddress(instruction, true);
    int registerIndex = instruction.operation() - Instructions::ST1 + 1;
    auto& rIi = rI(registerIndex);
    ComputerWord word(rIi.negative, 0, 0, 0, rIi[1], rIi[2]);
    copyFromRegister5(instruction, word, &memory[address]);
}