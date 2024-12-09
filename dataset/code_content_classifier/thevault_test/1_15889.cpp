void EventHandler::updateGestureTargetNodeForMouseEvent(const GestureEventWithHitTestResults& targetedEvent)
{
    ASSERT(m_frame == m_frame->localFrameRoot());

    // Behaviour of this function is as follows:
    // - Create the chain of all entered frames.
    // - Compare the last frame chain under the gesture to newly entered frame chain from the main frame one by one.
    // - If the last frame doesn't match with the entered frame, then create the chain of exited frames from the last frame chain.
    // - Dispatch mouseout/mouseleave events of the exited frames from the inside out.
    // - Dispatch mouseover/mouseenter events of the entered frames into the inside.

    // Insert the ancestors of the frame having the new target node to the entered frame chain
    WillBeHeapVector<RawPtrWillBeMember<LocalFrame>> enteredFrameChain;
    ASSERT(false); // BKTODO:
#if 0
    LocalFrame* enteredFrameInDocument = targetedEvent.hitTestResult().innerNodeFrame();
    while (enteredFrameInDocument) {
        enteredFrameChain.append(enteredFrameInDocument);
        Frame* parentFrame = enteredFrameInDocument->tree().parent();
        enteredFrameInDocument = parentFrame && parentFrame->isLocalFrame() ? toLocalFrame(parentFrame) : nullptr;
    }

    size_t indexEnteredFrameChain = enteredFrameChain.size();
    LocalFrame* exitedFrameInDocument = m_frame;
    WillBeHeapVector<RawPtrWillBeMember<LocalFrame>> exitedFrameChain;
    // Insert the frame from the disagreement between last frames and entered frames
    while (exitedFrameInDocument) {
        Node* lastNodeUnderTap = exitedFrameInDocument->eventHandler().m_nodeUnderMouse.get();
        if (!lastNodeUnderTap)
            break;

        LocalFrame* nextExitedFrameInDocument = nullptr;
        if (lastNodeUnderTap->isFrameOwnerElement()) {
            HTMLFrameOwnerElement* owner = toHTMLFrameOwnerElement(lastNodeUnderTap);
            if (owner->contentFrame() && owner->contentFrame()->isLocalFrame())
                nextExitedFrameInDocument = toLocalFrame(owner->contentFrame());
        }

        if (exitedFrameChain.size() > 0) {
            exitedFrameChain.append(exitedFrameInDocument);
        } else {
            LocalFrame* lastEnteredFrameInDocument = indexEnteredFrameChain ? enteredFrameChain[indexEnteredFrameChain-1] : nullptr;
            if (exitedFrameInDocument != lastEnteredFrameInDocument)
                exitedFrameChain.append(exitedFrameInDocument);
            else if (nextExitedFrameInDocument && indexEnteredFrameChain)
                --indexEnteredFrameChain;
        }
        exitedFrameInDocument = nextExitedFrameInDocument;
    }

    const PlatformGestureEvent& gestureEvent = targetedEvent.event();
    unsigned modifiers = gestureEvent.modifiers();
    PlatformMouseEvent fakeMouseMove(gestureEvent.position(), gestureEvent.globalPosition(),
        NoButton, PlatformEvent::MouseMoved, /* clickCount */ 0,
        static_cast<PlatformEvent::Modifiers>(modifiers),
        PlatformMouseEvent::FromTouch, gestureEvent.timestamp(), WebPointerProperties::PointerType::Mouse);

    // Update the mouseout/mouseleave event
    size_t indexExitedFrameChain = exitedFrameChain.size();
    while (indexExitedFrameChain) {
        LocalFrame* leaveFrame = exitedFrameChain[--indexExitedFrameChain];
        leaveFrame->eventHandler().updateMouseEventTargetNode(nullptr, fakeMouseMove);
    }

    // update the mouseover/mouseenter event
    while (indexEnteredFrameChain) {
        Frame* parentFrame = enteredFrameChain[--indexEnteredFrameChain]->tree().parent();
        if (parentFrame && parentFrame->isLocalFrame())
            toLocalFrame(parentFrame)->eventHandler().updateMouseEventTargetNode(toHTMLFrameOwnerElement(enteredFrameChain[indexEnteredFrameChain]->owner()), fakeMouseMove);
    }
#endif
}