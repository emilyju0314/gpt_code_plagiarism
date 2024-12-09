UserType::~UserType() {
    if (sets != nullptr) {
        delete sets;
    }
    if (dataPaths != nullptr) {
        delete dataPaths;
    }
}