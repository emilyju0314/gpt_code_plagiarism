void QLightTerminal::keyPressEvent(QKeyEvent *e) {
    e->accept();
    QString input = e->text();
    Qt::KeyboardModifiers mods = e->modifiers();
    int key = e->key();

    if (key == Qt::Key_Backspace) {
        if (mods.testFlag(Qt::KeyboardModifier::AltModifier)) {
            st->ttywrite("\033\177", 2, 1);
        } else {
            st->ttywrite("\177", 1, 1);
        }
        return;
    }

    // paste event
    if (
            key == 86
            && mods & Qt::KeyboardModifier::ShiftModifier
            && mods & Qt::KeyboardModifier::ControlModifier) {
        QClipboard *clipboard = QGuiApplication::clipboard();
        QString clippedText = clipboard->text();
        QByteArray data = clippedText.toLocal8Bit();
        st->ttywrite(data.data(), data.size(), 1);
        return;
    }

    // copy event
    if (
            key == 67
            && mods & Qt::KeyboardModifier::ShiftModifier
            && mods & Qt::KeyboardModifier::ControlModifier) {
        QClipboard *clipboard = QGuiApplication::clipboard();
        QString clippedText = QString(st->getsel());
        clipboard->setText(clippedText);
        return;
    }


    // normal input
    if (input != "") {
        QByteArray text;
        if (input.contains('\n')) {
            text = input.left(input.indexOf('\n') + 1).toUtf8();
        } else {
            text = e->text().toUtf8();
        }
        st->ttywrite(text, text.size(), 1);
    } else {
        // special keys
        // TODO: Add more short cuts
        int end = 24;

        if (key > keys[end].key || key < keys[0].key) {
            return;
        }

        for (int i = 0; i < end;) {
            int nextKey = keys[i].nextKey;
            if (key == keys[i].key) {
                for (int j = i; j < i + nextKey; j++) {
                    if (mods.testFlag(keys[j].mods)) {
                        st->ttywrite(keys[j].cmd, keys[j].cmd_size, 1);
                        return;
                    }
                }
            }
            i += nextKey;
        }
    }
}