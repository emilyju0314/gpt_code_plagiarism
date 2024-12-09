inline std::string trim_around(std::string inputString, 
                               const std::string::size_type pos) {
    trim_around_in_place(inputString, pos);
    return inputString;
}