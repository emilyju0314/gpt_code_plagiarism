void OCUFrame::onUpdate()
    {
        assert(wxThread::IsMain());

        updateVizModeAndViews();

        pnlFilmstrips[0]->onUpdateUI();
        pnlFilmstrips[1]->onUpdateUI();
        pnlFilmstrips[2]->onUpdateUI();
    }