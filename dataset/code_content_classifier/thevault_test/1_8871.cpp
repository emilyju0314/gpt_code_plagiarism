inline void trim_around_in_place(std::string& inputString,
                                 const std::string::size_type pos) {
    if (pos < inputString.size() && std::isspace(inputString[pos])) {
        auto rightEdge = inputString.find_first_not_of(Detail::WHITE_SPACE, pos);
        if (rightEdge != std::string::npos) {
            rightEdge -= 1;
        }
        if (rightEdge != pos) inputString.erase(pos+1, rightEdge-pos);

        auto leftEdge = inputString.find_last_not_of(Detail::WHITE_SPACE, pos);
        if (leftEdge == std::string::npos) {
            leftEdge = 0;
        } else {
            leftEdge += 1;
        }
        if (leftEdge != pos) inputString.erase(leftEdge, pos-leftEdge);
    }
}