void ts::tsswitch::InputExecutor::setCurrent(bool isCurrent)
{
    Guard lock(_mutex);
    _isCurrent = isCurrent;
}