static String selectMisspelledWord(const ContextMenu* defaultMenu, Frame* selectedFrame)
{
    // First select from selectedText to check for multiple word selection.
    String misspelledWord = selectedFrame->editor()->selectedText().stripWhiteSpace();

    // If some texts were already selected, we don't change the selection.
    if (!misspelledWord.isEmpty()) {
        // Don't provide suggestions for multiple words.
        if (!isASingleWord(misspelledWord))
            return String();
        return misspelledWord;
    }

    // Selection is empty, so change the selection to the word under the cursor.
    HitTestResult hitTestResult = selectedFrame->eventHandler()->
        hitTestResultAtPoint(selectedFrame->page()->contextMenuController()->hitTestResult().point(), true);
    Node* innerNode = hitTestResult.innerNode();
    VisiblePosition pos(innerNode->renderer()->positionForPoint(
        hitTestResult.localPoint()));

    if (pos.isNull())
        return misspelledWord; // It is empty.

    WebFrameImpl::selectWordAroundPosition(selectedFrame, pos);
    misspelledWord = selectedFrame->editor()->selectedText().stripWhiteSpace();

#if OS(DARWIN)
    // If misspelled word is still empty, then that portion should not be
    // selected. Set the selection to that position only, and do not expand.
    if (misspelledWord.isEmpty())
        selectedFrame->selection()->setSelection(VisibleSelection(pos));
#else
    // On non-Mac, right-click should not make a range selection in any case.
    selectedFrame->selection()->setSelection(VisibleSelection(pos));
#endif
    return misspelledWord;
}