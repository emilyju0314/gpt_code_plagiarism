static bool isASingleWord(const String& text)
{
    TextBreakIterator* it = wordBreakIterator(text.characters(), text.length());
    return it && textBreakNext(it) == static_cast<int>(text.length());
}