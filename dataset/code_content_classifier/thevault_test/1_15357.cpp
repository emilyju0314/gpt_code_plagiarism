string UserType::encodePath(string typePath, SetID setId, string setName) {
    char buffer[500];
    sprintf(buffer, "%s/%d_%s", typePath.c_str(), setId, setName.c_str());
    return string(buffer);
}