void CSLModel::CompModelName ()
{
    // Find the last component of the path
    size_t sep = xsbAircraftPath.find_last_of("\\/:");
    modelName = sep == std::string::npos ? xsbAircraftPath : xsbAircraftPath.substr(sep+1);
    // Add the id to it
    modelName += ' ';
    modelName += shortId;
}