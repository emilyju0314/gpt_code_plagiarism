TEST_F(HttpWithDnsOverHttpsTest, EndToEnd) {
  // Create and start http server.
  EmbeddedTestServer http_server(EmbeddedTestServer::Type::TYPE_HTTP);
  http_server.RegisterRequestHandler(base::BindRepeating(
      &HttpWithDnsOverHttpsTest::HandleDefaultConnect, base::Unretained(this)));
  EXPECT_TRUE(http_server.Start());

  // Set up an idle socket.
  HttpTransactionFactory* transaction_factory =
      request_context_.http_transaction_factory();
  HttpStreamFactory::JobFactory default_job_factory;
  HttpNetworkSession* network_session = transaction_factory->GetSession();
  base::RunLoop loop;
  TestHttpDelegate request_delegate(&loop);

  HttpStreamFactory* factory = network_session->http_stream_factory();
  HttpRequestInfo request_info;
  request_info.method = "GET";
  request_info.url = http_server.GetURL("localhost", "/preconnect");

  std::unique_ptr<HttpStreamRequest> request(factory->RequestStream(
      request_info, DEFAULT_PRIORITY, SSLConfig(), SSLConfig(),
      &request_delegate, false, false, NetLogWithSource()));
  loop.Run();

  ClientSocketPool::GroupId group_id(
      HostPortPair(request_info.url.host(), request_info.url.IntPort()),
      ClientSocketPool::SocketType::kHttp, PrivacyMode::PRIVACY_MODE_DISABLED,
      NetworkIsolationKey(), false /* disable_secure_dns */);
  EXPECT_EQ(network_session
                ->GetSocketPool(HttpNetworkSession::NORMAL_SOCKET_POOL,
                                ProxyServer::Direct())
                ->IdleSocketCountInGroup(group_id),
            1u);

  // The domain "localhost" is resolved locally, so no DNS lookups should have
  // occurred.
  EXPECT_EQ(doh_queries_served_, 0u);
  EXPECT_EQ(host_resolver_proc_->insecure_queries_served(), 0u);
  // A stream was established, but no HTTPS request has been made yet.
  EXPECT_EQ(test_https_requests_served_, 0u);

  // Make a request that will trigger a DoH query as well.
  TestDelegate d;
  d.set_allow_certificate_errors(true);
  GURL main_url = test_server_.GetURL("bar.example.com", "/test");
  std::unique_ptr<URLRequest> req(context()->CreateRequest(
      main_url, DEFAULT_PRIORITY, &d, TRAFFIC_ANNOTATION_FOR_TESTS));
  req->Start();
  base::RunLoop().Run();
  EXPECT_TRUE(test_server_.ShutdownAndWaitUntilComplete());
  EXPECT_TRUE(http_server.ShutdownAndWaitUntilComplete());
  EXPECT_TRUE(doh_server_.ShutdownAndWaitUntilComplete());

  // There should be two DoH lookups for "bar.example.com" (both A and AAAA
  // records are queried).
  EXPECT_EQ(doh_queries_served_, 2u);
  // The requests to the DoH server are pooled, so there should only be one
  // insecure lookup for the DoH server hostname.
  EXPECT_EQ(host_resolver_proc_->insecure_queries_served(), 1u);
  // There should be one non-DoH HTTPS request for the connection to
  // "bar.example.com".
  EXPECT_EQ(test_https_requests_served_, 1u);

  EXPECT_TRUE(d.response_completed());
  EXPECT_EQ(d.request_status(), 0);
  EXPECT_EQ(d.data_received(), kTestBody);
}