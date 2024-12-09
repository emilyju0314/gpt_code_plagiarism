bool Tool::readLine(const char *cPrompt) {
    initReadLine();

    string prompt = cPrompt;
    if (sOutputIsColor)
        prompt = ansiBold() + prompt + ansiReset();

    while (true) {
        sLineReader = this;
        char* line = linenoise(prompt.c_str());
        sLineReader = nullptr;
        if (line == nullptr) {
            // EOF (Ctrl-D)
            return false;
        } else if (*line == 0) {
            // No command was entered, so go round again:
            cout << "Please type a command, or Ctrl-D to exit.\n";
        } else if (*line) {
            // Got a command!
            // Add line to history so user can recall it later:
            linenoiseHistoryAdd(line);
#ifndef _MSC_VER
            linenoiseHistorySave(fixedUpPath(kHistoryFilePath).c_str());
#endif
            _argTokenizer.reset(line);
            linenoiseFree(line);
            return true;
        }
    }
}