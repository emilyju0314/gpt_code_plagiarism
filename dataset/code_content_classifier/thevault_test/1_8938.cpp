RenderPanel::RenderPanel(wxWindow* parent, int panelNumber, Ogre::SceneManager* sceneMgr, eu::nifti::ocu::gui::IMultiVizInputEventsHandler* evtHandler)
    : wxOgreRenderWindow(Ogre::Root::getSingletonPtr(), parent, wxID_ANY, wxDefaultPosition, parent->GetSize(), wxSUNKEN_BORDER, wxDefaultValidator, true)
    , mouse_x_(0)
    , mouse_y_(0)
    , sceneMgr(sceneMgr)
    , camera(NULL)
    , panelNumber(panelNumber)
    , evtHandler(evtHandler)
    {
        assert(panelNumber >= 0 && panelNumber <= 3);
        assert(sceneMgr != NULL);
        assert(evtHandler != NULL);

        SetFocus();
        Connect(wxEVT_CHAR, wxKeyEventHandler(RenderPanel::onKeyEvent), NULL, this);

        Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_MOTION, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_LEFT_UP, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
        Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(RenderPanel::onMouseEvent), NULL, this);
    }