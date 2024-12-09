ts::UString ts::ApplicationSharedLibrary::moduleName() const
{
    const UString name(PathPrefix(BaseName(fileName())));
    return !_prefix.empty() && name.find(_prefix) == 0 ? name.substr(_prefix.size()) : name;
}