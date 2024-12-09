void MenuUpdateCheckmarks ()
{
    // Menu item "Active"
    switch (XPMP2::RemoteGetStatus()) {
        case XPMP2::REMOTE_RECV_WAITING:
            XPLMSetMenuItemName(hMenu, MENU_ACTIVE, "Active (waiting for data)", 0);
            XPLMCheckMenuItem(hMenu, MENU_ACTIVE, xplm_Menu_Checked);
            break;

        case XPMP2::REMOTE_RECEIVING: {
            char s[50];
            snprintf (s, sizeof(s), "Active (%ld aircraft)", XPMPCountPlanes());
            XPLMSetMenuItemName(hMenu, MENU_ACTIVE, s, 0);
            XPLMCheckMenuItem(hMenu, MENU_ACTIVE, xplm_Menu_Checked);
            break;
        }
            
        default:
            XPLMSetMenuItemName(hMenu, MENU_ACTIVE, "Activate (currently inactive)", 0);
            XPLMCheckMenuItem(hMenu, MENU_ACTIVE, xplm_Menu_Unchecked);
            break;
    }
    
    // Menu item "TCAS Control" (status display)
    XPLMCheckMenuItem(hMenu, MENU_TCAS, XPMPHasControlOfAIAircraft() ? xplm_Menu_Checked : xplm_Menu_Unchecked);
}