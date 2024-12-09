const char* XPMPValidateResourceFiles (const char* resourceDir)
{
    // Store the resource dir
    if (!resourceDir || strlen(resourceDir) < 5) {
        LOG_MSG(logERR, ERR_RSRC_DIR_INVALID, resourceDir ? resourceDir : "<nullptr>");
        return "resourceDir too short / nullptr";
    }
    glob.resourceDir = TOPOSIX(resourceDir);
    
    // for path validation it must not end in the path separator
    if (glob.resourceDir.back() == PATH_DELIM_STD)
        glob.resourceDir.pop_back();    
    // Check for its existence
    if (!IsDir(glob.resourceDir)) {
        LOG_MSG(logERR, ERR_RSRC_DIR_UNAVAIL, glob.resourceDir.c_str());
        return "Resource directory unavailable";
    }
    // now add a separator to the path for ease of future use
    glob.resourceDir += PATH_DELIM_STD;
    
    // Validate and save a few files
    if (!FindResFile(RSRC_RELATED, glob.pathRelated))
        return "related.txt not found in resource directory";
    if (!FindResFile(RSRC_DOC8643, glob.pathDoc8643))
        return "Doc8643.txt not found in resource directory";
    if (!FindResFile(RSRC_MAP_ICONS, glob.pathMapIcons))
        return "MapIcons.png not found in resource directory";
    // this last one is not essentially required:
    if (!FindResFile(RSRC_OBJ8DATAREFS, glob.pathObj8DataRefs, false) &&
        glob.bObjReplDataRefs) {
        LOG_MSG(logWARN, ERR_RSRC_FILE_UNAVAIL,
                RSRC_OBJ8DATAREFS, glob.resourceDir.c_str());

    }
    
    // Success
    return "";
}