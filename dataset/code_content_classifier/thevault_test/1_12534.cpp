void ShortcutReceiverDialog::UpdateInterface()
    {
        MysticQt::KeyboardShortcutManager* shortcutManager = GetMainWindow()->GetShortcutManager();

        // check if the currently assigned shortcut is already taken by another shortcut
        m_conflictAction = shortcutManager->FindShortcut(m_key, m_orgGroup);
        if (m_conflictAction == nullptr || m_conflictAction == m_orgAction)
        {
            m_okButton->setToolTip("");
            m_label->setStyleSheet("");
            m_conflictKeyLabel->setStyleSheet("");
            m_conflictKeyLabel->setText("");
            m_conflictDetected = false;
        }
        else
        {
            m_label->setStyleSheet("color: rgb(244, 156, 28);");
            m_conflictKeyLabel->setStyleSheet("color: rgb(244, 156, 28);");

            m_conflictDetected = true;

            if (m_conflictAction)
            {
                m_okButton->setToolTip(QString("Assigning new shortcut will unassign '%1' automatically.").arg(m_conflictAction->m_qaction->text()));

                MysticQt::KeyboardShortcutManager::Group* conflictGroup = shortcutManager->FindGroupForShortcut(m_conflictAction);
                if (conflictGroup)
                {
                    m_conflictKeyLabel->setText(QString("Conflicts with: %1 -> %2").arg(FromStdString(conflictGroup->GetName())).arg(m_conflictAction->m_qaction->text()));
                }
                else
                {
                    m_conflictKeyLabel->setText(QString("Conflicts with: %1").arg(m_conflictAction->m_qaction->text()));
                }
            }
        }

        // adjust the label text to the new shortcut
        const QString keyText = KeyboardShortcutsWindow::ConstructStringFromShortcut(m_key);
        m_label->setText(keyText);
    }