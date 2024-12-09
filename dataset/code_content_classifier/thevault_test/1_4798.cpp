void IRQ_keyboardHandler()
{
  bool keydown = true;
  bool shift = false;
  int scancode;
  Key k;

  // Read from the keyboard's data
  scancode = kernel_inport(0x60);
  if (scancode < 0xE0) { // standard 1 byte keys
    if (scancode & 0x80) { // check if key is being released
      scancode -= 0x80;
      keydown = false;
    }    
    k = keymap[scancode];
  } else { // key is one of 17 multibyte keys
    scancode = kernel_inport(0x60); // get second byte
    if (scancode & 0x80) { // check if key is being released
      scancode -= 0x80;
      keydown = false;
    }    
    k = mb_keymap[scancode];
  }

  // need to call kernel_inport before returning
  if (kb_input_disabled) {
    return;
  }
 
  if (k.keycode != -1) {
    KeyEvent kevent;
    kevent.keycode = k.keycode;
    kb_state[kevent.keycode] = keydown;

    if (keydown && kevent.keycode == KEY_CAPS_LOCK) {
      caps_lock = caps_lock ? false : true;
    }

    if (kb_state[KEY_LSHIFT] || kb_state[KEY_RSHIFT]) {
      shift = true;
    }

    // only use caps lock for ascii characters
    if (k.ascii >= 'a' && k.ascii <= 'z') {
      if (caps_lock) {
        shift = !shift;
      }
    }

    kevent.ascii = shift ? k.shift_ascii : k.ascii;
    kevent.keydown = keydown;
   
    Terminal::sendKeyEvent(kevent);
  }
}