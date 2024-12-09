void Context::lookupAttributeMapping(TranslatedAttribute *attributes)
{
    for (int i = 0; i < MAX_VERTEX_ATTRIBS; i++)
    {
        if (attributes[i].active)
        {
            attributes[i].semanticIndex = getCurrentProgram()->getSemanticIndex(i);
        }
    }
}