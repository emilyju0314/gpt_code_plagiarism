int NodeGroupWindow::FindGroupIndexByWidget(QObject* widget) const
    {
        const auto foundGroup = AZStd::find_if(begin(m_widgetTable), end(m_widgetTable), [widget](const auto& tableEntry)
        {
            return tableEntry.m_widget == widget;
        });
        return foundGroup != end(m_widgetTable) ? foundGroup->m_groupIndex : MCore::InvalidIndexT<int>;
    }