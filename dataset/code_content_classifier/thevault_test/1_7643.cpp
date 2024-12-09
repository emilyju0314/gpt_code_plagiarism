void OneButton::attachDuringLongPress(callbackFunction newFunction)
{
  _longPressReTicks = 0;
  _duringLongPressFunc = newFunction;
}