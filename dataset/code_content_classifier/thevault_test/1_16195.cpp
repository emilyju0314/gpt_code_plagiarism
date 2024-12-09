TEST_F(RtaRpcTest, TransfersRtaTransaction)
{
  using namespace cryptonote;
  using namespace epee;
  epee::net_utils::http::http_simple_client http_client_wallet, http_client_daemon;

  http_client_wallet.set_server("localhost:28682",  boost::optional<epee::net_utils::http::login>());
  http_client_daemon.set_server("localhost:28681",  boost::optional<epee::net_utils::http::login>());
  epee::json_rpc::request<tools::wallet_rpc::COMMAND_RPC_TRANSFER_RTA::request> req = AUTO_VAL_INIT(req);
  epee::json_rpc::response<tools::wallet_rpc::COMMAND_RPC_TRANSFER_RTA::response, std::string> res = AUTO_VAL_INIT(res);

  req.method = "create_rta_tx";
  req.jsonrpc = "2.0";
  req.id = epee::serialization::storage_entry(0);

  req.params.graft_payment_id = "test-test-test";
  req.params.auth_sample_height = 243285;
  req.params.priority = 0;
  req.params.mixin = 7;
  req.params.get_tx_key = 1;


  // auth sample
  req.params.destinations.push_back({2000000000, "F8sHVwypnjw4fVdMvf3iZ5bisEUJ9DcQoZDBuC7aMRMFPCTHrGtPy7CBe5r68qHdjVKgdggg5NGpAD3r6JoQQiMBAoSEo7x"});
  req.params.destinations.push_back({2000000000, "F3udPm1csSbfMeFAm3DY6xFDyNjGJY4oiPMgrYdxvLC8X4Hom2yNa4oWV3nUcPKzU5R898Ds3xCVv5choXmA5zyiDtiiHkd"});
  req.params.destinations.push_back({2000000000, "FAu8g9xL8fRhDK6rQFhdKhWjZiRunC8Nj891VY99r8C5ipcdbAMmniHPfxB7TAEAQx9kSwJ6FugJTMnkPFtaVKobJ8RUP2Y"});
  req.params.destinations.push_back({2000000000, "F7gHVKGJUmH1Bzxq2e379KF5s8BUaSAhrZuQyTMuVKkKWVK9yHBsc47f6Dc5yFoVu12fPp64ooZdf9UDpa5gmp5j2ArzktC"});
  // destination wallet
  req.params.destinations.push_back({5000000000, "FBHdqDnz8YNU3TscB1X7eH25XLKaHmba9Vws2xwDtLKJWS7vZrii1vHVKAMGgRVz6WVcd2jN7qC1YEB4ZALUag2d9h1nnEu"});

  std::vector<crypto::public_key> pub_keys;
  {
    crypto::public_key pubkey;
    epee::string_tools::hex_to_pod("cdba49cbdece633266681b3c6f80f1085e7b3d3e0cca395d3986d10ab3ea0d6a", pubkey);
    pub_keys.push_back(pubkey);
    epee::string_tools::hex_to_pod("ce7cf758df6f2eb7f74d28730078be733cb953bda37a5f6e54ab09140f40e712", pubkey);
    pub_keys.push_back(pubkey);
    epee::string_tools::hex_to_pod("25b316d25e6c2dd8dd60fd983de9fbd5a9bb1fcf96d65bbb1c295708bafa00cb", pubkey);
    pub_keys.push_back(pubkey);
    epee::string_tools::hex_to_pod("914c13339fdfacdbbebe4c223d1900415432aab24f1f995823286104c7ac9eaa", pubkey);
    pub_keys.push_back(pubkey);
  }

  std::vector<crypto::secret_key> pvt_keys;
  {
    crypto::secret_key pvtkey;
    epee::string_tools::hex_to_pod("55260a5bf280cc91f9c36105b1dff9fef1559003f144d2fe577de8ba113ffc0b", pvtkey);
    pvt_keys.push_back(pvtkey);
    epee::string_tools::hex_to_pod("574fbb96e8af38f372e95608cab335f1f7d1895735004d1161c51ddba4988f09", pvtkey);
    pvt_keys.push_back(pvtkey);
    epee::string_tools::hex_to_pod("86cb6f1d884b2280c9ec703946b6476888d9aba78ca5e5c6367378c9ca347300", pvtkey);
    pvt_keys.push_back(pvtkey);
    epee::string_tools::hex_to_pod("546164cec18a87a729e83ff7683722ed184d91434638f8a04bf037b13aeb900f", pvtkey);
    pvt_keys.push_back(pvtkey);
  }

  for (const crypto::public_key &pkey : pub_keys) {
     req.params.supernode_keys.push_back(epee::string_tools::pod_to_hex(pkey));
  }

  bool r = net_utils::invoke_http_json("/json_rpc", req, res, http_client_wallet);
  ASSERT_TRUE(r);
  ASSERT_FALSE(res.result.tx_hash.empty());

#if 0
  cryptonote::transaction tx;
  std::string tx_blob;
  ASSERT_TRUE(string_tools::parse_hexstr_to_binbuff(res.result.tx_blob, tx_blob));
  ASSERT_TRUE(cryptonote::parse_and_validate_tx_from_blob(tx_blob, tx));
  COMMAND_RPC_SEND_RAW_TX::request tx_req;
  COMMAND_RPC_SEND_RAW_TX::response tx_resp;
  // Try to submit tx without rta signatures
  tx_req.tx_as_hex = res.result.tx_blob;
  tx_req.do_not_relay = false;
  r = net_utils::invoke_http_json("/sendrawtransaction", tx_req, tx_resp, http_client_daemon);
  ASSERT_TRUE(r);
  ASSERT_TRUE(tx_resp.rta_validation_failed);

  // try to submit tx with incorrect signatures
  std::string wrong_tx_id_str = res.result.tx_hash;
  for (int i = 0; i < 5; ++i) {
    wrong_tx_id_str[i] = '1';
  }
  crypto::hash wrong_tx_id;
  epee::string_tools::hex_to_pod(wrong_tx_id_str, wrong_tx_id);

  for (size_t i = 0; i < pub_keys.size(); ++i) {
    crypto::signature sign;
    crypto::generate_signature(wrong_tx_id, pub_keys[i], pvt_keys[i], sign);
    tx.rta_signatures.push_back({i, sign});
  }

  cryptonote::blobdata blob;
  tx_to_blob(tx, blob);
  tx_req.tx_as_hex = epee::string_tools::buff_to_hex_nodelimer(blob);
  r = net_utils::invoke_http_json("/sendrawtransaction", tx_req, tx_resp, http_client_daemon);
  ASSERT_TRUE(r);
  ASSERT_TRUE(tx_resp.rta_validation_failed);

  // try to submit tx with correct signatures
  crypto::hash tx_id;
  epee::string_tools::hex_to_pod(res.result.tx_hash, tx_id);
  tx.rta_signatures.clear();
  for (size_t i = 0; i < pub_keys.size(); ++i) {
    crypto::signature sign;
    crypto::generate_signature(tx_id, pub_keys[i], pvt_keys[i], sign);
    tx.rta_signatures.push_back({i, sign});
  }
  blob.clear();
  tx_to_blob(tx, blob);
  tx_req.tx_as_hex = epee::string_tools::buff_to_hex_nodelimer(blob);
  r = net_utils::invoke_http_json("/sendrawtransaction", tx_req, tx_resp, http_client_daemon);
  ASSERT_TRUE(r);
  ASSERT_FALSE(tx_resp.rta_validation_failed);
#endif

}