bool ToolBarPlugin::GetHasWindowWithObjectName(const AZStd::string& objectName)
    {
        if (m_bar.isNull())
        {
            return false;
        }

        // check if the object name is equal to the one of the dock widget
        return objectName == FromQtString(m_bar->objectName());
    }