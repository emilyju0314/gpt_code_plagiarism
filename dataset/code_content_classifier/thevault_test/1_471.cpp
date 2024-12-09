void load_tkinter_funcs(void)
{
    // Load Tk functions by searching all modules in current process.
    HMODULE hMods[1024];
    HANDLE hProcess;
    DWORD cbNeeded;
    unsigned int i;
    // Returns pseudo-handle that does not need to be closed
    hProcess = GetCurrentProcess();
    // Iterate through modules in this process looking for Tk names.
    if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) {
        for (i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
            if (load_tk(hMods[i])) {
                return;
            }
        }
    }
}