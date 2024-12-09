inline void PDBTemplateBase::deleteConstituentObject(void* deleteMe) const {

    // if we are a string
    if (info == String_TYPEID) {
        ((String*)deleteMe)->~String();

        // if we are a Handle
    } else if (info == Handle_TYPEID) {
        ((Handle<Nothing>*)deleteMe)->~Handle();

        // else if we are not derived from Object, do nothing
    } else if (info > 0) {
        // we are going to install the vTable pointer for an object of type ObjType into temp
        void* temp = nullptr;
        // std :: cout << "to getVTablePtr for deleteConsitituentObject" << info << std :: endl;
        ((Object*)&temp)->setVTablePtr(VTableMap::getVTablePtr((int16_t)info));

        // now call the deleter for that object type
        if (temp != nullptr) {
            ((Object*)&temp)->deleteObject(deleteMe);

            // in the worst case, we could not fix the vTable pointer, so try to use the object's
            // vTable pointer
        } else {
            ((Object*)deleteMe)->deleteObject(deleteMe);
        }
    }
}