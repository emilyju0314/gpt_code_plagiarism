size_t
POPState::cache_get(void **data, const char *component)
{
    // Construct lookup key
    std::string keystr = std::to_string(hash) + std::string(":") + std::string(component);

    // As implemented this shouldn't be necessary, since all our keys are below
    // the default size limit (511)
    //if (keystr.length()*sizeof(char) > mdb_env_get_maxkeysize(c->i->lod_env))
    //	return 0;

    mdb_txn_begin(c->i->lod_env, NULL, 0, &c->i->lod_txn);
    mdb_dbi_open(c->i->lod_txn, NULL, 0, &c->i->lod_dbi);
    mdb_key.mv_size = keystr.length()*sizeof(char);
    mdb_key.mv_data = (void *)keystr.c_str();
    int rc = mdb_get(c->i->lod_txn, c->i->lod_dbi, &mdb_key, &mdb_data);
    if (rc) {
	(*data) = NULL;
	return 0;
    }
    (*data) = mdb_data.mv_data;

    return mdb_data.mv_size;
}