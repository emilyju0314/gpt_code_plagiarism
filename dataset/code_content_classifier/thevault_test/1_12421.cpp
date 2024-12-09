void TagSelector::OnComboActivated(int index)
    {
        if (index < 0 || index >= m_combo->count())
        {
            return;
        }

        QString tag = m_combo->itemText(index);
        if (tag.isEmpty())
        {
            return;
        }

        // If the tag is not available, remove it so that it doesn't appear in the combo box.
        if (m_availableTags.indexOf(tag) == -1)
        {
            m_combo->removeItem(index);

            // Clear the text as the tag was not available.
            m_combo->setCurrentText("");
            return;
        }

        // Add a tag widget to the container. The tag widgets represent the currently selected tags.
        m_tagWidgets->AddTag(tag);

        // Clear the text as the tag got added to selection.
        m_combo->setCurrentText("");
    }