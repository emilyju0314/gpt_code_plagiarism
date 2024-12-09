static int keycodeToUnicode(
                char * uniChars, int maxChars,
                EventKind eKind,
                UInt32 keycode, UInt32 modifiers,
                UInt32 * deadKeyStatePtr,
                unsigned char,  // not used in this function
                unsigned short) // not used in this function
{
  // first get the keyboard mapping in a post 10.2 way
  
  Ptr resource;
  TextEncoding encoding;
  static TextEncoding lastEncoding = kTextEncodingMacRoman;
  int len = 0;
  KeyboardLayoutRef currentLayout = NULL;
  static KeyboardLayoutRef lastLayout = NULL;
  SInt32 currentLayoutId = 0;
  static SInt32 lastLayoutId;
  int hasLayoutChanged = false;
  static Ptr uchr = NULL;
  static Ptr KCHR = NULL;
  // ScriptCode currentKeyScript;
  
  KLGetCurrentKeyboardLayout(&currentLayout);
  if (currentLayout) {
    KLGetKeyboardLayoutProperty(currentLayout, kKLIdentifier, (const void**)&currentLayoutId);
    if ( (lastLayout != currentLayout) || (lastLayoutId != currentLayoutId) ) {
      lastLayout = currentLayout;
      lastLayoutId = currentLayoutId;
      uchr = NULL;
      KCHR = NULL;
      if ((KLGetKeyboardLayoutProperty(currentLayout, kKLuchrData, (const void**)&uchr) == noErr) && (uchr != NULL)) {
        // done
      } else if ((KLGetKeyboardLayoutProperty(currentLayout, kKLKCHRData, (const void**)&KCHR) == noErr) && (KCHR != NULL)) {
        // done
      }
      // FIXME No Layout property found. Now we have a problem. 
    }
  }
  if (hasLayoutChanged) {
    //deadKeyStateUp = deadKeyStateDown = 0;
    if (KCHR != NULL) {
      // FIXME this must not happen
    } else if (uchr == NULL) {
      KCHR = (Ptr) GetScriptManagerVariable(smKCHRCache);
    }
  }
  if (uchr != NULL) {
    // this is what I expect
    resource = uchr;
  } else {
    resource = KCHR;
    encoding = lastEncoding;
    // this is actually not supported by the following code and will likely crash
  }
  
  // now apply that keyboard mapping to our keycode
  
  int action;
  //OptionBits options = 0;
  // not used yet: OptionBits options = kUCKeyTranslateNoDeadKeysMask;
  unsigned long keyboardType;
  keycode &= 0xFF;
  modifiers = (modifiers >> 8) & 0xFF;
  keyboardType = LMGetKbdType();
  OSStatus status;
  UniCharCount actuallength;
  UniChar utext[10];
  
  switch(eKind) {     
    case kEventRawKeyDown:    action = kUCKeyActionDown; break;
    case kEventRawKeyUp:      action = kUCKeyActionUp; break;
    case kEventRawKeyRepeat:  action = kUCKeyActionAutoKey; break;
    default: return 0;
  }

  UInt32 deadKeyState = *deadKeyStatePtr;
  if ((action==kUCKeyActionUp)&&(*deadKeyStatePtr))
    deadKeyStatePtr = &deadKeyState;

  status = UCKeyTranslate(
                          (const UCKeyboardLayout *) uchr,
                          keycode, action, modifiers, keyboardType,
                          0, deadKeyStatePtr,
                          10, &actuallength, utext);

  if (noErr != status) {
    fprintf(stderr,"UCKeyTranslate failed: %d\n", (int) status);
    actuallength = 0;
  }

  // convert the list of unicode chars into utf8
  // FIXME no bounds check (see maxchars)
  unsigned i;
  for (i=0; i<actuallength; ++i) {
    len += fl_utf8encode(utext[i], uniChars+len);
  }
  uniChars[len] = 0;
  return len;
}