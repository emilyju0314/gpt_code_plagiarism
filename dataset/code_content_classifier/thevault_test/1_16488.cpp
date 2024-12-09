void DocumentMarkerController::removeMarkersFromMarkerMapVectorPair(Node* node, MarkerMapVectorPair* vectorPair, DocumentMarker::MarkerTypes markerTypes)
{
    if (!~(markerTypes & DocumentMarker::AllMarkers)) {
        delete vectorPair;
        m_markers.remove(node);
        if (RenderObject* renderer = node->renderer())
            renderer->repaint();
    } else {
        bool needsRepaint = false;
        Vector<DocumentMarker>& markers = vectorPair->first;
        Vector<IntRect>& rects = vectorPair->second;
        ASSERT(markers.size() == rects.size());
        for (size_t i = 0; i != markers.size();) {
            DocumentMarker marker = markers[i];

            // skip nodes that are not of the specified type
            if (!(marker.type & markerTypes)) {
                ++i;
                continue;
            }

            // pitch the old marker
            markers.remove(i);
            rects.remove(i);
            needsRepaint = true;
            // i now is the index of the next marker
        }

        // Redraw the node if it changed. Do this before the node is removed from m_markers, since
        // m_markers might contain the last reference to the node.
        if (needsRepaint) {
            RenderObject* renderer = node->renderer();
            if (renderer)
                renderer->repaint();
        }

        // delete the node's list if it is now empty
        if (markers.isEmpty()) {
            ASSERT(rects.isEmpty());
            m_markers.remove(node);
            delete vectorPair;
        }
    }
    if (m_markers.isEmpty())
        m_possiblyExistingMarkerTypes = 0;
}