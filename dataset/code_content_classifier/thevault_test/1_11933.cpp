void SetDefaultActionsEnabled(
    const QList<QAction*>& actions, const bool enabled)
{
    AZStd::for_each(
        actions.begin(), actions.end(),
        [enabled](QAction* action)
    {
        if (!action->property(s_reserved).toBool())
        {
            action->setEnabled(enabled);
        }
    });
}