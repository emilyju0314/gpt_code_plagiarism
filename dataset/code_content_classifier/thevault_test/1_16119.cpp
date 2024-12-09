std::string intToFixedLengthString(int intValue, int numDigits) {
    std::string stringValue = toString(intValue);
    while (stringValue.length() < numDigits) {
        stringValue = "0" + stringValue;
    }
    return stringValue;
}