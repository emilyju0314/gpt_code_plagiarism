static const char *AncestorAttrVal(const XMLElement* Elem, const char* AttrName)
{
    if (!Elem)
        return NULL;
    if (const XMLAttribute* Attr=Elem->FindAttribute(AttrName))
        return Attr->Value();
    const XMLElement* ParentElem=NULL;
    if (const XMLNode* ParentNode=Elem->Parent())
        ParentElem=ParentNode->ToElement();
    return AncestorAttrVal(ParentElem, AttrName);
}