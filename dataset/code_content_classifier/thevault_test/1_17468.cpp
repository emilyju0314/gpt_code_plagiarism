void PlanesShowHide ()
{
    gbVisible = !gbVisible;             // toggle setting
    if (pSamplePlane)
        pSamplePlane->SetVisible(gbVisible);
    if (pLegacyPlane)
        pLegacyPlane->SetVisible(gbVisible);
    if (hStdPlane)
        XPMPSetPlaneVisibility(hStdPlane, gbVisible);

    // Put a checkmark in front of menu item if planes are visible
    XPLMCheckMenuItem(hMenu, 1, gbVisible           ? xplm_Menu_Checked : xplm_Menu_Unchecked);
}