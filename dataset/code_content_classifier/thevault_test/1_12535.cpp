void ShortcutReceiverDialog::keyPressEvent(QKeyEvent* event)
    {
        if (event->key() ==  Qt::Key_Alt ||
            event->key() ==  Qt::Key_AltGr ||
            event->key() ==  Qt::Key_Shift ||
            event->key() ==  Qt::Key_Control ||
            event->key() ==  Qt::Key_Meta ||
            event->key() ==  Qt::Key_Tab)
        {
            return;
        }

        if (event->key() == Qt::Key_Escape)
        {
            // close the dialog when pressing ESC
            reject();
        }
        else
        {
            m_key = event->key() | event->modifiers();
        }

        UpdateInterface();

        event->accept();
    }