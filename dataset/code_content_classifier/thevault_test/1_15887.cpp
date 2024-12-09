WebInputEventResult EventHandler::updatePointerTargetAndDispatchEvents(const AtomicString& mouseEventType, Node* targetNode, int clickCount, const PlatformMouseEvent& mouseEvent)
{
    ASSERT(mouseEventType == EventTypeNames::mousedown
        || mouseEventType == EventTypeNames::mousemove
        || mouseEventType == EventTypeNames::mouseup);

    updateMouseEventTargetNode(targetNode, mouseEvent);
    if (!m_nodeUnderMouse)
        return WebInputEventResult::NotHandled;

#if 0 // BKTODO:
    AtomicString pointerEventType = pointerEventNameForMouseEventName(mouseEventType);
    unsigned short pointerButtonsPressed = MouseEvent::platformModifiersToButtons(mouseEvent.modifiers());

    // Make sure chorded buttons fire pointermove instead of pointerup/pointerdown.
    if ((pointerEventType == EventTypeNames::pointerdown && (pointerButtonsPressed & ~MouseEvent::buttonToButtons(mouseEvent.button())) != 0)
        || (pointerEventType == EventTypeNames::pointerup && pointerButtonsPressed != 0))
        pointerEventType = EventTypeNames::pointermove;

    WebInputEventResult result = dispatchPointerEvent(
        m_nodeUnderMouse.get(), pointerEventType, mouseEvent);

    if (result != WebInputEventResult::NotHandled && pointerEventType == EventTypeNames::pointerdown)
        m_preventMouseEventForPointerTypeMouse = true;
#else
    WebInputEventResult result = WebInputEventResult::NotHandled;
#endif

    if (!m_preventMouseEventForPointerTypeMouse) {
        GCRefPtr<MouseEvent> event = MouseEvent::create(mouseEventType, m_nodeUnderMouse->document().domWindow(), mouseEvent, clickCount, nullptr);
        bool dispatchResult = m_nodeUnderMouse->dispatchEvent(event);
        result = mergeEventResult(result, eventToEventResult(event.get(), dispatchResult));
    }

    return result;
}