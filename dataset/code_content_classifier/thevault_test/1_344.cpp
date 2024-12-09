Imc::group_t *Imc::getGroup(const string &name)
{
    map<string, group_t *>::iterator iter;
    iter = _groups.find(name);
    if(iter == _groups.end()) {
        return _groups[name] = new group_t;
    }
    return (*iter).second;
}