static std::string IdaHexify(int value) {
  if (value < 10) {
    return absl::StrCat(value);
  }
  return absl::StrCat(absl::AsciiStrToUpper(absl::StrCat(absl::Hex(value))),
                      "h");
}