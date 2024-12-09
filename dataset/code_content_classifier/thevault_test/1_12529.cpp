QString KeyboardShortcutsWindow::ConstructStringFromShortcut(QKeySequence key)
    {
        if (key.isEmpty())
        {
            return "not set";
        }

        return key.toString(QKeySequence::NativeText);
    }