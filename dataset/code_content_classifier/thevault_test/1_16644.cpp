void V8GCController::gcPrologue()
{
    v8::HandleScope scope;

#ifndef NDEBUG
    DOMObjectVisitor domObjectVisitor;
    visitDOMObjectsInCurrentThread(&domObjectVisitor);
#endif

    // Run through all objects with possible pending activity making their
    // wrappers non weak if there is pending activity.
    GCPrologueVisitor prologueVisitor;
    visitActiveDOMObjectsInCurrentThread(&prologueVisitor);

    // Create object groups.
    GrouperVisitor grouperVisitor;
    visitDOMNodesInCurrentThread(&grouperVisitor);
    visitDOMObjectsInCurrentThread(&grouperVisitor);
    grouperVisitor.applyGrouping();

    // Clean single element cache for string conversions.
    lastStringImpl = 0;
    lastV8String.Clear();
}