void Computer::executeDIV(const InstructionWord& instruction) {
    int32_t valueA = std::abs(rA.value());
    int32_t valueX = std::abs(rX.value());
    int64_t dividend = (static_cast<int64_t>(valueA) << 30) + static_cast<int64_t>(valueX);
    if (rA.negative) {
        dividend = -dividend;
    }
    ComputerWord word;
    int address = getIndexedAddress(instruction, true);
    copyToRegister5(instruction, memory[address], &word);
    int32_t divisor = word.value();
    if (divisor == 0) {
        throw RuntimeError(_lineOffset, "Divisor cannot be 0");
    }
    int64_t quotient = dividend / divisor;
    if (std::abs(quotient) >= (1 << 30)) {
        overflow = true;
        quotient %= (1 << 30);
    }
    int32_t remainder = dividend % divisor;
    rA.set(static_cast<int32_t>(quotient));
    rX.set(remainder);
}