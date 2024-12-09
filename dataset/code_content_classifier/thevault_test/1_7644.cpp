void OneButton::attachDuringLongPress(callbackFunction newFunction, int repeatMS)
{
  _longPressReTicks = repeatMS;
  _duringLongPressFunc = newFunction;
}