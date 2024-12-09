json::json Invoices::History(const json::json& params, bool fHelp)
        {
            /* First ensure that transaction version 2 active, as the conditions required for invoices were not enabled until v2 */
            const uint32_t nCurrent = TAO::Ledger::CurrentTransactionVersion();
            if(nCurrent < 2 || (nCurrent == 2 && !TAO::Ledger::TransactionVersionActive(runtime::unifiedtimestamp(), 2)))
                throw APIException(-254, "Invoices API not yet active.");

            return Objects::History(params, TAO::Register::OBJECTS::NONSTANDARD, std::string("Invoice"));
        }