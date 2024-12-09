void handleSubscribe(std::shared_ptr<SnakeConnectionState> state,
                         ix::WebSocket& ws,
                         const AppConfig& appConfig,
                         const nlohmann::json& pdu,
                         uint64_t pduId)
    {
        std::string channel = pdu["body"]["channel"];
        state->subscriptionId = channel;

        std::stringstream ss;
        ss << state->appkey() << "::" << channel;

        state->appChannel = ss.str();

        ix::RedisClient& redisClient = state->subscriptionRedisClient;
        int port = appConfig.redisPort;

        auto urls = appConfig.redisHosts;
        std::string hostname(urls[0]);

        // Connect to redis first
        if (!redisClient.connect(hostname, port))
        {
            std::stringstream ss;
            ss << "Cannot connect to redis host " << hostname << ":" << port;
            handleError("rtm/subscribe", ws, pduId, ss.str());
            return;
        }

        // Now authenticate, if needed
        if (!appConfig.redisPassword.empty())
        {
            std::string authResponse;
            if (!redisClient.auth(appConfig.redisPassword, authResponse))
            {
                std::stringstream ss;
                ss << "Cannot authenticated to redis";
                handleError("rtm/subscribe", ws, pduId, ss.str());
                return;
            }
        }

        std::string filterStr;
        if (pdu["body"].find("filter") != pdu["body"].end())
        {
            std::string filterStr = pdu["body"]["filter"];
        }
        state->streamSql = std::make_unique<StreamSql>(filterStr);
        state->id = 0;
        state->onRedisSubscribeCallback = [&ws, state](const std::string& messageStr) {
            auto msg = nlohmann::json::parse(messageStr);

            msg = msg["body"]["message"];

            if (state->streamSql->valid() && !state->streamSql->match(msg))
            {
                return;
            }

            nlohmann::json response = {
                {"action", "rtm/subscription/data"},
                {"id", state->id++},
                {"body",
                 {{"subscription_id", state->subscriptionId}, {"position", "0-0"}, {"messages", {msg}}}}};

            ws.sendText(response.dump());
        };

        state->onRedisSubscribeResponseCallback = [&ws, state, pduId](const std::string& redisResponse) {
            std::stringstream ss;
            ss << "Redis Response: " << redisResponse << "...";
            ix::CoreLogger::log(ss.str().c_str());

            // Success
            nlohmann::json response = {{"action", "rtm/subscribe/ok"},
                                       {"id", pduId},
                                       {"body", {{"subscription_id", state->subscriptionId}}}};
            ws.sendText(response.dump());
        };

        {
            std::stringstream ss;
            ss << "Subscribing to " << state->appChannel << "...";
            ix::CoreLogger::log(ss.str().c_str());
        }

        auto subscription = [&redisClient, state, &ws, pduId]
        {
            if (!redisClient.subscribe(state->appChannel, 
                                       state->onRedisSubscribeResponseCallback,
                                       state->onRedisSubscribeCallback))
            {
                std::stringstream ss;
                ss << "Error subscribing to channel " << state->appChannel;
                handleError("rtm/subscribe", ws, pduId, ss.str());
                return;
            }
        };

        state->subscriptionThread = std::thread(subscription);
    }