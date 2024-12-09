static void UpdateMenus(
    QMenu* menu, const bool defaultActionsSuspended,
    QHash<int, std::function<void()>>& updateCallbacks,
    QList<QAction*> topLevelMenuActions, int depth)
{
    const auto actions = menu->actions();
    const int actionCount = actions.size();
    int suspendedActionCounter =  0;

    for (auto action : actions)
    {
        // if an action is itself a menu, we want to check its
        // own menu actions (children), but only one level down
        if (action->menu() && depth == 0)
        {
            UpdateMenus(
                action->menu(), defaultActionsSuspended,
                updateCallbacks, topLevelMenuActions, depth + 1);
        }

        if (ActionSuspended(defaultActionsSuspended, action))
        {
            suspendedActionCounter++;
            continue;
        }

        // call all update callbacks for the given menu
        // only do this at the level of the menu we clicked/hovered
        const auto id = action->data().toInt();
        if (updateCallbacks.contains(id) && depth == 0)
        {
            updateCallbacks.value(id)();
        }
    }

    // check if we are a top level menu action
    if (AZStd::find(
        topLevelMenuActions.begin(), topLevelMenuActions.end(),
        menu->menuAction()) == topLevelMenuActions.end())
    {
        // if we're not a top level menu action, we want to disable
        // the sub menu if none of the child actions are active, otherwise
        // ensure the menu is returned to an enabled state
        menu->menuAction()->setEnabled(
            defaultActionsSuspended
                ? suspendedActionCounter != actionCount
                : true);
    }
}