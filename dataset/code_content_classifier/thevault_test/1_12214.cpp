QModelIndex ViewportCameraSelectorWindow::moveCursor(CursorAction cursorAction, [[maybe_unused]] Qt::KeyboardModifiers modifiers)
        {
            switch (cursorAction)
            {
            case CursorAction::MoveUp:
            {
                return GetPreviousIndex();
            }
            case CursorAction::MoveDown:
            {
                return GetNextIndex();
            }
            case CursorAction::MoveNext:
            {
                return GetNextIndex();
            }
            case CursorAction::MovePrevious:
            {
                return GetPreviousIndex();
            }
            default:
                return currentIndex();
            }
        }