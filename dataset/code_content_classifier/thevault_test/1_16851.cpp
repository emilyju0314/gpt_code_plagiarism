void SlamMap::createTxtMapFile(std::string fileName, std::vector<int> mapData) {

    FILE* out = fopen(fileName.c_str(), "w");

    for(int s = 0; s < mapData.size(); s++) {
        fprintf(out, "%d ", mapData[s]);

        if (s && s%mapWidth_ == 0) {

            fprintf(out, "\n");

        }
    }
    fclose(out);
}