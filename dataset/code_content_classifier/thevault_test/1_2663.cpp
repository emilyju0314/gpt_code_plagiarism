bool
MicroCore::get_tx(const crypto::hash& tx_hash, transaction& tx)
{
    if (m_blockchain_storage.have_tx(tx_hash))
    {
        // get transaction with given hash
        tx = m_blockchain_storage.get_db().get_tx(tx_hash);
    }
    else
    {
        cerr << "MicroCore::get_tx tx does not exist in blockchain: "
                << epee::string_tools::pod_to_hex(tx_hash) << endl;
        return false;
    }


    return true;
}