TEST(parseUC, firstCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    uint32_t counter = 2;

    fstream file(OUTPUT_FILE_PARSE_UC, ios::out);

    string circuitPath = CIRCUIT_PATH_UC;
    istringstream iss("[ 0 1 ] out 2 3");
    parseUC(circuitPath, iss, file, wires, counter);
    file.close();

    EXPECT_EQ(wires[2], 3);
    EXPECT_EQ(wires[3], 5);
    EXPECT_EQ(counter, 6);

    fstream file2(OUTPUT_FILE_PARSE_UC, ios::in);
    string line;

    getNextLine(file2, line);
    EXPECT_EQ (line, "P 0 1 2 3");
    getNextLine(file2, line);
    EXPECT_EQ(line, "Y 1 2 4");
    getNextLine(file2, line);
    EXPECT_EQ(line, "U 3 4 5");
    EXPECT_FALSE(getNextLine(file2, line));
    file2.close();
}