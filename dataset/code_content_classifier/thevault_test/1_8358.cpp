void NewCredWizard::NotifyNewIdentity(bool notify_ui)
{
    bool default_off = true;
    bool isk5 = false;

    /* For backwards compatibility, we assume that if there is no
       primary identity or if the primary identity is not from the
       Kerberos v5 identity provider, then the default for all
       plug-ins is to be disabled and must be explicitly enabled. */

    /* All the privileged interaction panels are assumed to no longer
       be valid */
    khui_cw_clear_all_privints(nc);

    khui_cw_lock_nc(nc);

    if (nc->n_identities == 0 ||
        !kcdb_identity_by_provider(nc->identities[0], L"Krb5Ident"))

        default_off = true;

    else {

        isk5 = true;
        default_off = false;

    }

    if (default_off) {
        unsigned i;

        for (i=0; i < nc->n_types; i++) {
            nc->types[i].nct->flags |= KHUI_NCT_FLAG_DISABLED;
        }
    } else if (isk5) {
        unsigned i;

        for (i=0; i < nc->n_types; i++) {
            nc->types[i].nct->flags &= ~KHUI_NCT_FLAG_DISABLED;
        }
    }

    nc->privint.initialized = FALSE;

    if (nc->subtype == KHUI_NC_SUBTYPE_ACQPRIV_ID)
        nc->persist_privcred = TRUE;
    else
        nc->persist_privcred = FALSE;

    if (nc->persist_identity)
        kcdb_identity_release(nc->persist_identity);
    nc->persist_identity = NULL;

    khui_cw_unlock_nc(nc);

    NotifyTypes( WMNC_IDENTITY_CHANGE, (LPARAM) nc, TRUE);

    khui_cw_lock_nc(nc);

    PrepCredTypes();

    /* The currently selected privileged interaction panel also need
       to be reset.  However, we let nc_layout_privint() handle that
       since it may need to hide the window. */

    if (nc->subtype == KHUI_NC_SUBTYPE_NEW_CREDS &&
        nc->n_identities > 0 &&
        nc->identities[0]) {
        khm_int32 f = 0;

        kcdb_identity_get_flags(nc->identities[0], &f);

        if (!(f & KCDB_IDENT_FLAG_DEFAULT)) {
            nc->set_default = FALSE;
        }

        if (!(f & KCDB_IDENT_FLAG_CRED_INIT)) {

            std::wstring cant = LoadStringResource(IDS_NC_CANTINIT);
            m_privint.m_noprompts.SetText(KHERR_ERROR, cant.c_str());
        }
    }

    /* The m_noprompts panel will be shown if the provider does
       not provide us with a password change dialog.  The default
       text would need to be changed to indicate that the identity
       does not support password changes. */
    if (nc->subtype == KHUI_NC_SUBTYPE_PASSWORD &&
        nc->n_identities > 0 &&
        nc->identities[0]) {

        std::wstring wont = LoadStringResource(IDS_NC_NOPWCHANGE);
        m_privint.m_noprompts.SetText(KHERR_ERROR, wont.c_str());
    }

    khui_cw_unlock_nc(nc);

    if (notify_ui) {

        m_idsel.UpdateLayout();

        if (page == NC_PAGE_CREDOPT_ADV ||
            page == NC_PAGE_CREDOPT_BASIC ||
            page == NC_PAGE_CREDOPT_WIZ ||
            page == NC_PAGE_PASSWORD) {

            m_privint.UpdateLayout();

        }
    }
}