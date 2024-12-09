void IonFinder::Params::printVersion(std::ostream& out) const{
    out << "ionFinder v" << PROG_VERSION_MAJOR << "."
        << PROG_VERSION_MINOR << "."
        << PROG_VERSION_PATCH << NEW_LINE;
}