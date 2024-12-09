void MenuUpdateSenders ()
{
    // Simple case first: There is no sender
    if (rcGlob.gmapSender.empty()) {
        // If we show anything we must remove it
        if (numSendersInMenu > 0) {
            XPLMClearAllMenuItems(hSenders);
            XPLMAppendMenuItem(hSenders, "(none)", (void*)MENU_SENDER, 0);
            numSendersInMenu = 0;
        }
        return;
    }
    
    // There are senders, fill in their details
    if (numSendersInMenu == 0)      // physically there's always one menu item that we can re-use
        numSendersInMenu++;
    
    // Cycle over senders and update textual information
    int idx = 0;
    for (const mapSenderTy::value_type& p: rcGlob.gmapSender)
    {
        const SenderTy& snd = p.second;
        
        // Put together plugin name, IP address, number of aircraft
        std::string s (STR_N(snd.settings.name));
        if (!snd.bLocal) {
            s += " @ ";
            s += snd.sFrom;
        }
        s += ": ";
        s += std::to_string(snd.mapAc.size());
        s += " aircraft";
        
        // Do we need a new menu item or can we update an existing one?
        if (idx < numSendersInMenu)
            XPLMSetMenuItemName(hSenders, idx, s.c_str(), 0);
        else {
            XPLMAppendMenuItem(hSenders, s.c_str(), (void*)MENU_SENDER, 0);
            numSendersInMenu++;
        }
        idx++;
    }
    
    // Remove left-over menu items
    while (idx < numSendersInMenu)
        XPLMRemoveMenuItem(hSenders, --numSendersInMenu);
}