TEST(handleCircuit, privateCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    uint32_t counter = 2;

    fstream file(OUTPUT_FILE_HANDLE_CIRCUIT, ios::out);
    fstream pfile(PROG_OUTPUT_HANDLE_CIRCUIT, ios::out);

    string path = PATH_HANDLE_CIRCUIT;
    string circuitFile = CIRCUIT_FILE_PRIV_HANDLE_CIRCUIT;
    istringstream iss("[ 0 1 ] out 2 3");

    handleCircuits(path, circuitFile, iss, file, pfile, wires, counter);
    file.close();
    pfile.close();

    string circuitPath = CIRCUIT_PATH_PRIV_HANDLE_CIRCUIT;
    istringstream iss2("[ 0 1 ] out 2 3");
    map<uint32_t, uint32_t> wires2;
    wires2[0] = 0;
    wires2[1] = 1;
    uint32_t counter2 = 2;
    fstream refFile(OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT, ios::out);
    parseUC(circuitPath, iss2, refFile, wires2, counter2);
    refFile.close();

    EXPECT_EQ(wires[2], wires2[2]);
    EXPECT_EQ(wires[3], wires2[3]);
    EXPECT_EQ(counter, counter2);

    fstream file3(OUTPUT_FILE_HANDLE_CIRCUIT, ios::in);
    fstream file4(OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT, ios::in);
    string line, line2;

    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ (line, line2);
    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ(line, line2);
    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ(line, line2);
    EXPECT_FALSE(getNextLine(file3, line));
    file3.close();
    file4.close();
}