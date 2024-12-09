int NMTConfig::LoadFromFile(const char* configFN, char** args) 
{
    ifstream f(configFN, ios::in);
    CheckNTErrors(f.is_open(), "Failed to open the config file");

    int argsNum = 0;

    /* parse arguments from the file */
    string key, value;
    while (f >> key >> value && argsNum < (MAX_PARAM_NUM - 1)) {
        if (args[argsNum] != NULL) {
            delete[] args[argsNum];
        }
        if (args[argsNum + 1] != NULL) {
            delete[] args[argsNum + 1];
        }
        args[argsNum] = new char[1024];
        args[argsNum + 1] = new char[1024];
        strcpy(args[argsNum++], key.c_str());
        strcpy(args[argsNum++], value.c_str());
    }

    /* record the number of arguments */
    return argsNum;
}