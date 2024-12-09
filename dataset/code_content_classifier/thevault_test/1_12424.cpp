KeyboardShortcutManager::Group* KeyboardShortcutManager::FindGroupForShortcut(Action* action) const
    {
        const auto foundGroup = AZStd::find_if(begin(m_groups), end(m_groups), [action](const AZStd::unique_ptr<Group>& group)
        {
            const auto foundAction = AZStd::find_if(begin(group->GetActions()), end(group->GetActions()), [action](const AZStd::unique_ptr<Action>& actionInGroup)
            {
                return action == actionInGroup.get();
            });
            return foundAction != end(group->GetActions()) ? foundAction->get() : nullptr;
        });
        return foundGroup != end(m_groups) ? foundGroup->get() : nullptr;
    }