void CSLObj::DetermineWhichObjToLoad ()
{
    // 1. Determine if we need to access a copied file at all
    const bool bDoReplTextures = glob.bObjReplTextures && (!texture.empty() || !text_lit.empty());
    if (!glob.bObjReplDataRefs && !bDoReplTextures)
        return;
    
    // 2. Compute that copied file name
    pathOrig = path;                // Save the original name
    // remove the current extension
    RemoveExtension(path);
    // if we need to replace texture then a texture id should become part of the file name
    if (bDoReplTextures) {
        std::string addTxt = texture.empty() ? text_lit : texture;
        RemoveExtension(addTxt);
        path += '.';
        path += addTxt;
    }
    // always add 'xpmp2.obj' as the final extension
    path += ".xpmp2.obj";
    
    // 3. Test if that copied file already exists
    if (ExistsFile(path))
        // It does exist, so no new copy is needed
        pathOrig.clear();
}