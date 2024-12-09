static constexpr std::pair<WasmPointer, WasmSize> splitSpan(WasmSpan span) {
    auto unsigned_result = static_cast<uint64_t>(span);
    uint64_t minor_part = unsigned_result & 0xFFFFFFFFLLU;
    uint64_t major_part = (unsigned_result >> 32u) & 0xFFFFFFFFLLU;

    return {minor_part, major_part};
  }