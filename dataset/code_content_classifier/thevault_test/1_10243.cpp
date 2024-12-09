TEST(parseUC, middleCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    wires[3] = 100;
    wires[4] = 168;
    wires[5] = 193;
    wires[6] = 204;
    uint32_t counter = 250;

    fstream file(OUTPUT_FILE_PARSE_UC, ios::out);

    string circuitPath = CIRCUIT_PATH_UC;
    istringstream iss("3 5 out 7 8");
    parseUC(circuitPath, iss, file, wires, counter);
    file.close();

    EXPECT_EQ(wires[7], 251);
    EXPECT_EQ(wires[8], 253);
    EXPECT_EQ(counter, 254);

    fstream file2(OUTPUT_FILE_PARSE_UC, ios::in);
    string line;

    getNextLine(file2, line);
    EXPECT_EQ (line, "P 100 193 250 251");
    getNextLine(file2, line);
    EXPECT_EQ(line, "Y 193 250 252");
    getNextLine(file2, line);
    EXPECT_EQ(line, "U 251 252 253");
    EXPECT_FALSE(getNextLine(file2, line));
    file2.close();
}