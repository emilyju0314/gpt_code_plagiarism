QLibHomeScreen::~QLibHomeScreen()
{
    HMI_DEBUG("qlibhomescreen", "called.");
    if (mp_hs != NULL) {
        delete mp_hs;
    }
}