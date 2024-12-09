void _keyEvent(CGKeyCode keyCode, bool isDown){
    CGEventRef keyEvent = CGEventCreateKeyboardEvent(NULL,keyCode , isDown);
    CGEventPost(kCGHIDEventTap, keyEvent);
    CFRelease(keyEvent);
  }