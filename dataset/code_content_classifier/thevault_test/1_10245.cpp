TEST(parseUC, wrongNumberOfOutputs) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;
    istringstream iss("[ 0 1 ] out 3 4 5");
    string circuitPath = CIRCUIT_PATH_UC;

    try {
        fstream file(OUTPUT_FILE_PARSE_UC, ios::out);
        parsePublicCircuit(circuitPath, iss, file, wires, counter);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        string exception = e.what();
        EXPECT_EQ("Parsing Exception!", exception);
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}