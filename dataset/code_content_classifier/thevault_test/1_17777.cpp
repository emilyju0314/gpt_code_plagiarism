static optional<variant<std::string, Tileset>> convertURLOrTileset(const Convertible& value, Error& error) {
    auto urlVal = objectMember(value, "url");
    if (!urlVal) {
        optional<Tileset> tileset = convert<Tileset>(value, error);
        if (!tileset) {
            return nullopt;
        }
        return { *tileset };
    }

    optional<std::string> url = toString(*urlVal);
    if (!url) {
        error.message = "source url must be a string";
        return nullopt;
    }

    return { *url };
}