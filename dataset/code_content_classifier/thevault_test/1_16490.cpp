JavaInstance* ExtractJavaInstance(NPObject* obj)
{
    if (obj->_class == &JavaNPObjectClass)
        return reinterpret_cast<JavaNPObject*>(obj)->m_instance.get();
    return 0;
}