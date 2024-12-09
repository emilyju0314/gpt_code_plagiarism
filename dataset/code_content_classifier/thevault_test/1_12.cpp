bool
POPState::cache_write(const char *component, std::stringstream &s)
{
    // Prepare inputs for writing
    std::string keystr = std::to_string(hash) + std::string(":") + std::string(component);
    std::string buffer = s.str();

    // As implemented this shouldn't be necessary, since all our keys are below
    // the default size limit (511)
    //if (keystr.length()*sizeof(char) > mdb_env_get_maxkeysize(c->i->lod_env))
    //	return false;

    // Write out key/value to LMDB database, where the key is the hash
    // and the value is the serialized LoD data
    //
    mdb_txn_begin(c->i->lod_env, NULL, 0, &c->i->lod_txn);
    mdb_dbi_open(c->i->lod_txn, NULL, 0, &c->i->lod_dbi);
    mdb_key.mv_size = keystr.length()*sizeof(char);
    mdb_key.mv_data = (void *)keystr.c_str();
    mdb_data.mv_size = buffer.length();
    mdb_data.mv_data = (void *)buffer.c_str();
    int rc = mdb_put(c->i->lod_txn, c->i->lod_dbi, &mdb_key, &mdb_data, 0);
    mdb_txn_commit(c->i->lod_txn);

    return (!rc) ? true : false;
}