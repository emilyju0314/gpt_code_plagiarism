void FrameView::updateLifecyclePhasesInternal(LifeCycleUpdateOption phases)
{
    std::optional<TemporaryChange<bool>> isUpdatingAllLifecyclePhasesScope;
    if (phases == AllPhases)
        isUpdatingAllLifecyclePhasesScope.emplace(m_isUpdatingAllLifecyclePhases, true);

    // This must be called from the root frame, since it recurses down, not up.
    // Otherwise the lifecycles of the frames might be out of sync.
    ASSERT(m_frame->isLocalRoot());

    // Updating layout can run script, which can tear down the FrameView.
    RefPtrWillBeRawPtr<FrameView> protector(this);

    if (shouldThrottleRendering()) {
        updateViewportIntersectionsForSubtree(std::min(phases, OnlyUpToCompositingCleanPlusScrolling));
        return;
    }

    updateStyleAndLayoutIfNeededRecursive();
    ASSERT(lifecycle().state() >= DocumentLifecycle::LayoutClean);

    if (phases == OnlyUpToLayoutClean) {
        updateViewportIntersectionsForSubtree(phases);
        return;
    }

    if (LayoutView* view = layoutView()) {
        {
            TRACE_EVENT1("devtools.timeline", "UpdateLayerTree", "data", InspectorUpdateLayerTreeEvent::data(m_frame.get()));

            // This was required for slimming paint v1 but is only temporarily
            // needed for slimming paint v2.
            view->compositor()->updateIfNeededRecursive();
            scrollContentsIfNeededRecursive();

            ASSERT(lifecycle().state() >= DocumentLifecycle::CompositingClean);

            if (phases == AllPhases) {
                invalidateTreeIfNeededRecursive();

                if (view->compositor()->inCompositingMode())
                    scrollingCoordinator()->updateAfterCompositingChangeIfNeeded();

                updateCompositedSelectionIfNeeded();
            }
        }

        if (phases == AllPhases) {
            if (RuntimeEnabledFeatures::slimmingPaintV2Enabled())
                updatePaintProperties();

            if (!m_frame->document()->printing())
                synchronizedPaint();

            if (RuntimeEnabledFeatures::frameTimingSupportEnabled())
                updateFrameTimingRequestsIfNeeded();

            if (RuntimeEnabledFeatures::slimmingPaintV2Enabled())
                pushPaintArtifactToCompositor();

            ASSERT(!view->hasPendingSelection());
            ASSERT((m_frame->document()->printing() && lifecycle().state() == DocumentLifecycle::PaintInvalidationClean)
                || lifecycle().state() == DocumentLifecycle::PaintClean);
        }
    }

    updateViewportIntersectionsForSubtree(phases);
}