KeyboardShortcutManager::Action* KeyboardShortcutManager::FindAction(const QString& actionName, AZStd::string_view groupName) const
    {
        const Group* group = FindGroupByName(groupName);
        if (!group)
        {
            return nullptr;
        }

        Action* action = group->FindActionByName(actionName, false);
        if (action)
        {
            return action;
        }
        return group->FindActionByName(actionName, true);
    }