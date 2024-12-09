TEST (handleInputs, clientAndServerInput) {
    string current = "C";
    istringstream iss("[ 0 5 ]");
    map<uint32_t, uint32_t> wires;
    testInputs(current, iss, 0, 5, OUTPUT_FILE_HANDLE_INPUTS, 0, wires);
    current = "S";
    istringstream iss2("[ 6 18 ]");
    testInputs(current, iss2, 6, 18, OUTPUT_FILE_HANDLE_INPUTS, 6, wires);
}