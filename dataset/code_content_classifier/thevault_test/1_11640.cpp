bool QsKineticScroller::eventFilter(QObject* object, QEvent* event)
{
   const QEvent::Type eventType = event->type();
   const bool isMouseAction = QEvent::MouseButtonPress == eventType
      || QEvent::MouseButtonRelease == eventType;
   const bool isMouseEvent = isMouseAction || QEvent::MouseMove == eventType;

   if( !isMouseEvent || !d->scrollArea )
     return false;

   if( isMouseAction && d->ignoreList.removeAll(event) > 0 ) // This event is ignored
      return false;

   QMouseEvent* const mouseEvent = static_cast<QMouseEvent*>(event);
   switch( eventType )
   {
   case QEvent::MouseButtonPress:
      {
         SCROLL_DEBUG() << "[scroll] press pos" << mouseEvent->globalPos();
         d->isPressed = true;
         d->lastPressPoint = mouseEvent->globalPos();
         d->lastScrollBarPosition = d->scrollArea->verticalScrollBar()->value();
         if( d->isMoving ) // press while kinetic scrolling, so stop
            d->stopMotion();
      }
      break;
   case QEvent::MouseMove:
      {
         SCROLL_DEBUG() << "[scroll] move pos" << mouseEvent->globalPos();
         if( !d->isMoving )
         {
            // A few move events are ignored as "click jitter", but after that we
            // assume that the user is doing a click & drag
            if( d->ignoredMouseMoves < gMaxIgnoredMouseMoves )
               ++d->ignoredMouseMoves;
            else
            {
               d->ignoredMouseMoves = 0;
               d->isMoving = true;
               d->lastMouseYPos = mouseEvent->globalPos().y();
               if( !d->kineticTimer.isActive() )
                  d->kineticTimer.start(gTimerInterval);
            }
         }
         else
         {
            // manual scroll
            const int dragDistance = mouseEvent->globalPos().y() - d->lastPressPoint.y();
            const int finalScrollPos = d->lastScrollBarPosition - dragDistance;
            d->scrollArea->verticalScrollBar()->setValue(finalScrollPos);
            SCROLL_DEBUG() << "[scroll] manual scroll to" << finalScrollPos;
         }
      }
      break;
   case QEvent::MouseButtonRelease:
      {
         const QPoint& releasePos = mouseEvent->pos();
         SCROLL_DEBUG() << "[scroll] release pos" << releasePos;
         d->isPressed = false;
         d->ignoredMouseMoves = 0;
         // Looks like the user wanted a single click. Simulate the click,
         // as the events were already consumed
         const bool isEditWidget = (NULL != qobject_cast<QLineEdit*>(object)
                                  || NULL != qobject_cast<QTextEdit*>(object->parent()));
         const bool isCombobox = NULL != qobject_cast<QComboBox*>(object);
         const bool isInterestingObject = (object == d->scrollArea->viewport() || isEditWidget
            || isCombobox);
         if( !d->isMoving && isInterestingObject )
         {
            QMouseEvent* mousePress = new QMouseEvent(QEvent::MouseButtonPress,
               releasePos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
            QMouseEvent* mouseRelease = new QMouseEvent(QEvent::MouseButtonRelease,
               releasePos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);

            // Ignore these two
            d->ignoreList << mousePress;
            d->ignoreList << mouseRelease;

            QApplication::postEvent(object, mousePress);
            QApplication::postEvent(object, mouseRelease);
            if (isEditWidget) {
                SCROLL_DEBUG() << "[scroll] trying to open keyboard";
                QEvent *openKeyboard = new QEvent(QEvent::RequestSoftwareInputPanel);
                QApplication::postEvent(object, openKeyboard);
            }
         }
      }
      break;
   default:
      break;
   }

   return true; // filter event
}