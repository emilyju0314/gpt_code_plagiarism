void EventHandler::updateGestureHoverActiveState(const HitTestRequest& request, Element* innerElement)
{
    ASSERT(m_frame == m_frame->localFrameRoot());

    ASSERT(false); // BKTODO:
#if 0
    WillBeHeapVector<RawPtrWillBeMember<LocalFrame>> newHoverFrameChain;
    LocalFrame* newHoverFrameInDocument = innerElement ? innerElement->document().frame() : nullptr;
    // Insert the ancestors of the frame having the new hovered node to the frame chain
    // The frame chain doesn't include the main frame to avoid the redundant work that cleans the hover state.
    // Because the hover state for the main frame is updated by calling Document::updateHoverActiveState
    while (newHoverFrameInDocument && newHoverFrameInDocument != m_frame) {
        newHoverFrameChain.append(newHoverFrameInDocument);
        Frame* parentFrame = newHoverFrameInDocument->tree().parent();
        newHoverFrameInDocument = parentFrame && parentFrame->isLocalFrame() ? toLocalFrame(parentFrame) : nullptr;
    }

    RefPtrWillBeRawPtr<Node> oldHoverNodeInCurDoc = m_frame->document()->hoverNode();
    RefPtrWillBeRawPtr<Node> newInnermostHoverNode = innerElement;

    if (newInnermostHoverNode != oldHoverNodeInCurDoc) {
        size_t indexFrameChain = newHoverFrameChain.size();

        // Clear the hover state on any frames which are no longer in the frame chain of the hovered elemen
        while (oldHoverNodeInCurDoc && oldHoverNodeInCurDoc->isFrameOwnerElement()) {
            LocalFrame* newHoverFrame = nullptr;
            // If we can't get the frame from the new hover frame chain,
            // the newHoverFrame will be null and the old hover state will be cleared.
            if (indexFrameChain > 0)
                newHoverFrame = newHoverFrameChain[--indexFrameChain];

            HTMLFrameOwnerElement* owner = toHTMLFrameOwnerElement(oldHoverNodeInCurDoc.get());
            if (!owner->contentFrame() || !owner->contentFrame()->isLocalFrame())
                break;

            LocalFrame* oldHoverFrame = toLocalFrame(owner->contentFrame());
            Document* doc = oldHoverFrame->document();
            if (!doc)
                break;

            oldHoverNodeInCurDoc = doc->hoverNode();
            // If the old hovered frame is different from the new hovered frame.
            // we should clear the old hovered node from the old hovered frame.
            if (newHoverFrame != oldHoverFrame)
                doc->updateHoverActiveState(request, nullptr);
        }
    }
#endif

    // Recursively set the new active/hover states on every frame in the chain of innerElement.
    m_frame->document()->updateHoverActiveState(request, innerElement);
}