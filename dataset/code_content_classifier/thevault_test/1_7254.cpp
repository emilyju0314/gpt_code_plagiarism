static double do_queued_events( double time = 0.0 ) 
{
  static bool been_here = false;
  static RgnHandle rgn;
  
  // initialize events and a region that enables mouse move events
  if (!been_here) {
    rgn = NewRgn();
    Point mp;
    GetMouse(&mp);
    SetRectRgn(rgn, mp.h, mp.v, mp.h, mp.v);
    SetEventMask(everyEvent);
    been_here = true;
  }
  OSStatus ret;
  static EventTargetRef target = 0;
  if ( !target ) 
  {
    target = GetEventDispatcherTarget();

    EventHandlerUPP dispatchHandler = NewEventHandlerUPP( carbonDispatchHandler ); // will not be disposed by Carbon...
    static EventTypeSpec dispatchEvents[] = {
        { kEventClassWindow, kEventWindowShown },
        { kEventClassWindow, kEventWindowHidden },
        { kEventClassWindow, kEventWindowActivated },
        { kEventClassWindow, kEventWindowDeactivated },
        { kEventClassWindow, kEventWindowClose },
        { kEventClassKeyboard, kEventRawKeyDown },
        { kEventClassKeyboard, kEventRawKeyRepeat },
        { kEventClassKeyboard, kEventRawKeyUp },
        { kEventClassKeyboard, kEventRawKeyModifiersChanged },
        { kEventClassMouse, kEventMouseDown },
        { kEventClassMouse, kEventMouseUp },
        { kEventClassMouse, kEventMouseMoved },
        { kEventClassMouse, 11 }, // MightyMouse wheels
        { kEventClassMouse, kEventMouseWheelMoved },
        { kEventClassMouse, kEventMouseDragged },
        { kEventClassFLTK, kEventFLTKBreakLoop },
        { kEventClassFLTK, kEventFLTKDataReady } };
    ret = InstallEventHandler( target, dispatchHandler, GetEventTypeCount(dispatchEvents), dispatchEvents, 0, 0L );
    static EventTypeSpec appEvents[] = {
        { kEventClassCommand, kEventCommandProcess } };
    ret = InstallApplicationEventHandler( dispatchHandler, GetEventTypeCount(appEvents), appEvents, 0, 0L );
  }

  got_events = 0;

  // Check for re-entrant condition
  if ( dataready.IsThreadRunning() )
    { dataready.CancelThread(DEBUGTEXT("AVOID REENTRY\n")); }

  // Start thread to watch for data ready
  if ( dataready.GetNfds() )
      { dataready.StartThread((void*)GetCurrentEventQueue()); }

  fl_unlock_function();

  EventRef event;
  EventTimeout timeout = time;
  if (!ReceiveNextEvent(0, NULL, timeout, true, &event)) {
    got_events = 1;
    OSErr ret = SendEventToEventTarget( event, target );
    if (ret!=noErr) {
      EventRecord clevent;
      ConvertEventRefToEventRecord(event, &clevent);
      if (clevent.what==kHighLevelEvent) {
        ret = AEProcessAppleEvent(&clevent);
      }
    }
    if (   ret==eventNotHandledErr
        && GetEventClass(event)==kEventClassMouse
        && GetEventKind(event)==kEventMouseDown ) {
      WindowRef win; Point pos;
      GetEventParameter(event, kEventParamMouseLocation, typeQDPoint,
        NULL, sizeof(pos), NULL, &pos);
      if (MacFindWindow(pos, &win)==inMenuBar) {
        MenuSelect(pos);
      }
    }
    ReleaseEvent( event );
  }

  fl_lock_function();

#if CONSOLIDATE_MOTION
  if (send_motion && send_motion == fl_xmousewin) {
    send_motion = 0;
    Fl::handle(FL_MOVE, fl_xmousewin);
  }
#endif

  return time;
}