std::string
xml_safe_get(const TiXmlElement* elem, const std::string& attr) {
    if (elem == nullptr) return "closed";
    if (elem->Attribute(attr.c_str()) != nullptr) return std::string(elem->Attribute(attr.c_str()));
    return "closed";
}