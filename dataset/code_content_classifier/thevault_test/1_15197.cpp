std::vector<State> ParseLine(std::string line) {
    std::istringstream sline(line); // input stream
    int n; // target variable to store parsed integers
    char c; // target variable to parse char delimmiter

    vector<State> row;
    while(sline >> n >> c && c == ',') {
        if (n == 0) row.push_back(State::kEmpty);
        else row.push_back(State::kObstacle);
    }
    return row;
}