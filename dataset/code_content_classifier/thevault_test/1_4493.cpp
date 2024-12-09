void CMpegAudEncPropertyPageAdv::InitPropertiesDialog(HWND hwndParent)
{
    EnableControls(hwndParent, TRUE);

    //
    // initialize radio bottons
    //
    DWORD dwChannelMode;
    m_pAEProps->get_ChannelMode(&dwChannelMode);
    CheckRadioButton(hwndParent, IDC_RADIO_STEREO, IDC_RADIO_MONO, IDC_RADIO_STEREO + dwChannelMode);

    if (dwChannelMode == MPG_MD_JOINT_STEREO)
        EnableWindow(GetDlgItem(hwndParent, IDC_CHECK_FORCE_MS), TRUE);
    else
        EnableWindow(GetDlgItem(hwndParent, IDC_CHECK_FORCE_MS), FALSE);

    //
    // initialize checkboxes
    //
    DWORD dwEnforceVBRmin;
    m_pAEProps->get_EnforceVBRmin(&dwEnforceVBRmin);
    CheckDlgButton(hwndParent, IDC_CHECK_ENFORCE_MIN, dwEnforceVBRmin ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwVoiceMode;
    m_pAEProps->get_VoiceMode(&dwVoiceMode);
    CheckDlgButton(hwndParent, IDC_CHECK_VOICE, dwVoiceMode ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwKeepAllFreq;
    m_pAEProps->get_KeepAllFreq(&dwKeepAllFreq);
    CheckDlgButton(hwndParent, IDC_CHECK_KEEP_ALL_FREQ, dwKeepAllFreq ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwStrictISO;
    m_pAEProps->get_StrictISO(&dwStrictISO);
    CheckDlgButton(hwndParent, IDC_CHECK_STRICT_ISO, dwStrictISO ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwNoShortBlock;
    m_pAEProps->get_NoShortBlock(&dwNoShortBlock);
    CheckDlgButton(hwndParent, IDC_CHECK_DISABLE_SHORT_BLOCK, dwNoShortBlock ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwXingEnabled;
    m_pAEProps->get_XingTag(&dwXingEnabled);
    CheckDlgButton(hwndParent, IDC_CHECK_XING_TAG, dwXingEnabled ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwForceMS;
    m_pAEProps->get_ForceMS(&dwForceMS);
    CheckDlgButton(hwndParent, IDC_CHECK_FORCE_MS, dwForceMS ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwModeFixed;
    m_pAEProps->get_ModeFixed(&dwModeFixed);
    CheckDlgButton(hwndParent, IDC_CHECK_MODE_FIXED, dwModeFixed ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwOverlap;
    m_pAEProps->get_SampleOverlap(&dwOverlap);
    CheckDlgButton(hwndParent, IDC_CHECK_OVERLAP, dwOverlap ? BST_CHECKED : BST_UNCHECKED);

    DWORD dwStopTime;
    m_pAEProps->get_SetDuration(&dwStopTime);
    CheckDlgButton(hwndParent, IDC_CHECK_STOP, dwStopTime ? BST_CHECKED : BST_UNCHECKED);
}