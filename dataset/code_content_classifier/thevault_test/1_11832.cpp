URSequencePoint* UndoStack::PopTop()
        {
            if (m_SequencePointsBuffer.empty())
            {
                return nullptr;
            }

            //CHB: Slice will notify if there is something to slice,
            //so we may not want to call it again below
            //however if it does not slice we just notify again below
            //so this may generate two calls so we may want to optimize this into one call
            //or something... remember if sliced notified then dont notify again maybe
            Slice();

            URSequencePoint* returned = m_SequencePointsBuffer[m_Cursor];
            m_SequencePointsBuffer.pop_back();
            returned->m_isPosted = false;
            m_Cursor = int(m_SequencePointsBuffer.size()) - 1;

            if (m_notify)
            {
                m_notify->OnUndoStackChanged();
            }

            return returned;
        }