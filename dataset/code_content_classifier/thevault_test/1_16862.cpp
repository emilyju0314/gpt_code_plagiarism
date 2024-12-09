void PathGroup::determinePathTravels(std::string &pathTravels) {
    int counter = 0;
    std::istringstream paths(pathTravels);
    std::string line;
    int scanfError = 0;
    float targetX, targetY;

        while (std::getline(paths, line) && (counter < MAX_NUM_PATH_TRAVELS)) {

            // print out read line
            std::cout << line << std::endl;

            // parse informations from file:
            scanfError = sscanf(line.c_str(), "%f;%f", &targetX, &targetY);

            this->travels[counter] = new PathTravel(targetX, targetY, 0.0f);

            if (scanfError <= 0)
                break;

            counter++;
        }
}