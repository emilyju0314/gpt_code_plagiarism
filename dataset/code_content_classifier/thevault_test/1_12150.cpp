bool StyledDockWidget::isSingleFloatingChild()
    {
        // Check if our parent is a fancy docking QMainWindow with no central
        // widget, which means it is one of the floating main windows
        DockMainWindow* parentMainWindow = qobject_cast<DockMainWindow*>(parentWidget());
        if (parentMainWindow && parentMainWindow->HasFancyDocking() && !parentMainWindow->centralWidget())
        {
            // Make sure the parent dock widget of the main window is floating to handle
            // cases where there are nested main windows
            StyledDockWidget* parentDockWidget = qobject_cast<StyledDockWidget*>(parentMainWindow->parentWidget());
            if (parentDockWidget && parentDockWidget->isFloating())
            {
                bool singleFloating = true;
                for (QDockWidget* dockWidget : parentMainWindow->findChildren<QDockWidget*>(QString(), Qt::FindDirectChildrenOnly))
                {
                    if (dockWidget->isVisible() && dockWidget != this)
                    {
                        singleFloating = false;
                        break;
                    }
                }

                return singleFloating;
            }
        }

        return false;
    }