void CPRequestAIAgain (void*)
{
    // Well...we just try again ;-)
    XPMPMultiplayerEnable(CPRequestAIAgain);
    MenuUpdateCheckmarks();
}