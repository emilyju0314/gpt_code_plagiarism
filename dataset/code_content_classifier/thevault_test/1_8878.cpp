void minter::tx::create_data_from_type() {
    switch (get_type()) {
    case tx_send_coin_type.type():
        m_data_raw = tx_send_coin_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_sell_coin_type.type():
        m_data_raw = tx_sell_coin_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_sell_all_coins_type.type():
        m_data_raw = tx_sell_all_coins_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_buy_coin_type.type():
        m_data_raw = tx_buy_coin_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_create_coin_type.type():
        m_data_raw = tx_create_coin_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_declare_candidacy_type.type():
        m_data_raw = tx_declare_candidacy_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_delegate_type.type():
        m_data_raw = tx_delegate_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_unbond_type.type():
        m_data_raw = tx_unbond_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_redeem_check_type.type():
        m_data_raw = tx_redeem_check_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_set_candidate_on_type.type():
        m_data_raw = tx_set_candidate_on_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_set_candidate_off_type.type():
        m_data_raw = tx_set_candidate_off_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_create_multisig_address_type.type():
        m_data_raw = tx_create_multisig_address_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_multisend_type.type():
        m_data_raw = tx_multisend_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_edit_candidate_type.type():
        m_data_raw = tx_edit_candidate_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_set_halt_block_type.type():
        m_data_raw = tx_set_halt_block_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_recreate_coin_type.type():
        m_data_raw = tx_recreate_coin_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_edit_coin_owner_type.type():
        m_data_raw = tx_edit_coin_owner_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_edit_multisig_type.type():
        m_data_raw = tx_edit_multisig_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_edit_candidate_public_key_type.type():
        m_data_raw = tx_edit_candidate_public_key_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_price_vote_type.type():
        m_data_raw = tx_price_vote_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_add_liquidity_type.type():
        m_data_raw = tx_add_liquidity_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_remove_liquidity_type.type():
        m_data_raw = tx_remove_liquidity_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_sell_swap_pool_type.type():
        m_data_raw = tx_sell_swap_pool_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_buy_swap_pool_type.type():
        m_data_raw = tx_buy_swap_pool_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_sell_all_swap_pool_type.type():
        m_data_raw = tx_sell_all_swap_pool_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_create_swap_pool_type.type():
        m_data_raw = tx_create_swap_pool_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_create_token_type.type():
        m_data_raw = tx_create_token_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_edit_candidate_commission_type.type():
        m_data_raw = tx_edit_candidate_commission_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_mint_token_type.type():
        m_data_raw = tx_mint_token_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_burn_token_type.type():
        m_data_raw = tx_burn_token_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_recreate_token_type.type():
        m_data_raw = tx_recreate_token_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_vote_commission_type.type():
        m_data_raw = tx_vote_commission_type.create(shared_from_this(), get_data_raw());
        break;
    case tx_vote_update_type.type():
        m_data_raw = tx_vote_update_type.create(shared_from_this(), get_data_raw());
        break;
    default:
        throw std::runtime_error("Unknown tx type: " + minter::utils::to_string(m_type));
    }
}