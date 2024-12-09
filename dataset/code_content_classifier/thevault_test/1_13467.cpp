struct ast_cli_entry* Garbage::allocEntry()
{
    void* entry_pure = calloc(sizeof(struct ast_cli_entry), 1);
    BOOST_ASSERT(entry_pure);
    m_garbage.push_back(entry_pure);
    struct ast_cli_entry* entry =
        static_cast<struct ast_cli_entry*>(entry_pure);

    return entry;
}