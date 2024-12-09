KeyEvent::Type Keypad::getKeyEvent() {
    if (buttons_.onPress(RawKey::kFolder1))
        return KeyEvent::kFolder1;
    else if (buttons_.onPress(RawKey::kFolder2))
        return KeyEvent::kFolder2;
    else if (buttons_.onPress(RawKey::kFolder3))
        return KeyEvent::kFolder3;
    else if (buttons_.onPress(RawKey::kFolder4))
        return KeyEvent::kFolder4;
    else if (buttons_.onPress(RawKey::kFolder5))
        return KeyEvent::kFolder5;
    else if (buttons_.onPress(RawKey::kFolder6))
        return KeyEvent::kFolder6;
    else if (buttons_.onPress(RawKey::kFolder7))
        return KeyEvent::kFolder7;
    else if (buttons_.onPress(RawKey::kFolder8))
        return KeyEvent::kFolder8;
    else if (buttons_.onPress(RawKey::kFolder9))
        return KeyEvent::kFolder9;
    //else if (buttons_.onPressAfter(RawKey::kPlayPause, kDurationLongPressMs))
    //    return KeyEvent::kStop;
    else if (buttons_.onPressAfter(RawKey::kNext, kDurationLongPressMs))
        return KeyEvent::kConfigMode;
    else if (buttons_.onReleaseBefore(RawKey::kPlayPause,kDurationShortPressMs))
        return KeyEvent::kPlayPause;
    else if (buttons_.onReleaseBefore(RawKey::kNext, kDurationShortPressMs))
        return KeyEvent::kNext;
    else if (buttons_.onReleaseBefore(RawKey::kPrev, kDurationShortPressMs))
        return KeyEvent::kPrev;
    else
        return KeyEvent::kNone;
}