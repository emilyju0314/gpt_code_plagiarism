void NewCredWizard::PrepCredTypes()
{
    khm_size i;
    khm_handle idpro = NULL;
    khm_int32 ctype = KCDB_CREDTYPE_INVALID;

    /* if we have an identity, we should make sure that the identity
       credentials type is at the top of the list.  So we mark the
       identity credentials type and let the compare function take
       over. */
    if (nc->n_identities > 0) {
        khm_size cb;

        cb = sizeof(ctype);
        kcdb_identity_get_attr(nc->identities[0], KCDB_ATTR_TYPE,
                               NULL, &ctype, &cb);
    }

    for (i=0; i < nc->n_types; i++) {
        nc->types[i].is_id_credtype = (ctype != KCDB_CREDTYPE_INVALID &&
                                       nc->types[i].nct->type == ctype);
    }

    qsort(nc->types, nc->n_types, sizeof(*(nc->types)), tab_sort_func);

    for (i=0; i < nc->n_types; i++) {
        nc->types[i].nct->ordinal = i+1;
    }
}