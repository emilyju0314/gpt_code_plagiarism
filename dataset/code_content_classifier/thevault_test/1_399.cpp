json::json Users::Create(const json::json& params, bool fHelp)
        {
            /* JSON return value. */
            json::json ret;

            /* Pin parameter. */
            SecureString strPin;

            /* Check for username parameter. */
            if(params.find("username") == params.end())
                throw APIException(-127, "Missing username");

            /* Check for password parameter. */
            if(params.find("password") == params.end())
                throw APIException(-128, "Missing password");

            /* Check for pin parameter. Extract the pin. */
            if(params.find("pin") != params.end())
                strPin = SecureString(params["pin"].get<std::string>().c_str());
            else if(params.find("PIN") != params.end())
                strPin = SecureString(params["PIN"].get<std::string>().c_str());
            else
                throw APIException(-129, "Missing PIN");

            /* Extract the username  */
            SecureString strUsername = params["username"].get<std::string>().c_str();

            /* Extract the password */
            SecureString strPassword = params["password"].get<std::string>().c_str();

            /* Check username length */
            if(strUsername.length() < 2)
                throw APIException(-191, "Username must be a minimum of 2 characters");

            /* Check password length */
            if(strPassword.length() < 8)
                throw APIException(-192, "Password must be a minimum of 8 characters");

            /* Check pin length */
            if(strPin.length() < 4)
                throw APIException(-193, "Pin must be a minimum of 4 characters");

            /* The genesis transaction  */
            TAO::Ledger::Transaction tx;

            /* Create the sig chain genesis transaction */
            create_sig_chain(strUsername, strPassword, strPin, tx);

            /* Build a JSON response object. */
            ret["version"]   = tx.nVersion;
            ret["sequence"]  = tx.nSequence;
            ret["timestamp"] = tx.nTimestamp;
            ret["genesis"]   = tx.hashGenesis.ToString();
            ret["nexthash"]  = tx.hashNext.ToString();
            ret["prevhash"]  = tx.hashPrevTx.ToString();
            ret["pubkey"]    = HexStr(tx.vchPubKey.begin(), tx.vchPubKey.end());
            ret["signature"] = HexStr(tx.vchSig.begin(),    tx.vchSig.end());
            ret["hash"]      = tx.GetHash().ToString();

            return ret;
        }