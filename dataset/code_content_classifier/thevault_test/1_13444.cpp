const Ice::ObjectPtr Adapter::createObject(const std::string& object_id)
{
    Ice::ObjectPtr result;
    // FIXME!!! bad code
    if (object_id == obj::MESSAGES)
        result = new ipc::MessagesProxy(getFactory(), this);
    else if (object_id == obj::RESOURCES)
        result = new ipc::ResourcesProxy(getFactory());
    else if (object_id == obj::DEV)
        result = new ipc::DevProxy(getFactory());
    else if (object_id == obj::MODULES)
        result = new ipc::ModulesProxy(getFactory());
    else
        throw klk::Exception(__FILE__, __LINE__, "Unknown object id: %s",
                             object_id.c_str());
    return result;
}