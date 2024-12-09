void Seed::readFile(std::string name) {
        
    // open the file
    std::string fileName = name + "_106.lif";
    std::ifstream inputFile;
    inputFile.open(fileName.c_str());
    
    // read the header line
    std::string header;
    getline(inputFile,header);
    
    // read the coordinates from file
    coord myCoord;
    pattern.clear();
    while (inputFile >> myCoord.x >> myCoord.y) {
        pattern.push_back(myCoord);
    }
    inputFile.close();
    
    // calculate the length of the pattern and extent in x and y dimensions
    std::sort(pattern.begin(), pattern.end(), byX);
    sizeX = pattern.back().x - pattern.front().x + 1;
    std::sort(pattern.begin(), pattern.end(), byY);
    sizeY = pattern.back().y - pattern.front().y + 1;
    length = static_cast<int>(pattern.size());
}