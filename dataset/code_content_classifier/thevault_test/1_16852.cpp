void SlamMap::createTxtPositionFile() {

    //std::string mapCounterStr = std::to_string(mapCounter_);
    //std::string positionDataFile = "position" + mapCounterStr +  ".txt";
    std::string positionDataFile = "position.txt";
    FILE* out = fopen(positionDataFile.c_str(), "w");
    fprintf(out, "%d\n%d\n%.2f", getPixelX(), getPixelY(), theta);
    fclose(out);

}