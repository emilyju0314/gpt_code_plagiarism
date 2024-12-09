void TimeViewPlugin::RenderElementTimeHandles(QPainter& painter, uint32 dataWindowHeight, const QPen& pen)
    {
        // for all tracks
        for (const TimeTrack* track : m_tracks)
        {
            if (track->GetIsVisible() == false)
            {
                continue;
            }

            // for all elements
            const size_t numElems = track->GetNumElements();
            for (size_t i = 0; i < numElems; ++i)
            {
                const TimeTrackElement* elem = track->GetElement(i);

                // if the element has to show its time handles, do it
                if (elem->GetShowTimeHandles())
                {
                    // calculate the dimensions
                    int32 startX, startY, width, height;
                    elem->CalcDimensions(&startX, &startY, &width, &height);

                    // draw the lines
                    painter.setPen(pen);
                    //painter.setRenderHint(QPainter::Antialiasing);
                    painter.drawLine(startX, 0, startX, dataWindowHeight);
                    painter.drawLine(startX + width, 0, startX + width, dataWindowHeight);
                }
            }
        }
    }