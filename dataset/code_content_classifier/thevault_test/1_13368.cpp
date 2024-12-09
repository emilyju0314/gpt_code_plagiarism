static int table_handler(
    netsnmp_mib_handler               *handler,
    netsnmp_handler_registration      *reginfo,
    netsnmp_agent_request_info        *reqinfo,
    netsnmp_request_info              *requests)
{
    try
    {

        switch (reqinfo->mode)
        {
            /*
             * Read-support (also covers GetNext requests)
             */
        case MODE_GET:
            for (netsnmp_request_info* request=requests;
                 request; request=request->next)
            {
                snmp::TableRow *row =
                    static_cast<snmp::TableRow *>(
                        netsnmp_extract_iterator_context(request));

                if (!row)
                {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }


                netsnmp_table_request_info *table_info =
                    netsnmp_extract_table_info(request);

                // check range
                if (row->size() < table_info->colnum)
                {
                    DEBUGMSGTL((SNMPID.c_str(), "%s",
                                "Error in table_handler(): "
                                "data out of range\n"));
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }

                // retrive value
                const StringWrapper val((*row)[table_info->colnum - 1]);
                switch (table_info->colnum)
                {
                case COLUMN_TASKNAME:
                case COLUMN_INPUTSOURCE:
                case COLUMN_OUTPUTSOURCE:
                    snmp_set_var_typed_value(
                        request->requestvb,
                        ASN_OCTET_STR,
                        reinterpret_cast<const u_char*>(val.toString().c_str()),
                        val.toString().size());
                    break;
                case COLUMN_DURATION:
                case COLUMN_TOTALDURATION:
                {
                  u_int64_t duration = val.toUInt64();
                  struct counter64 c64;
                  c64.low = duration;
                  c64.high = duration >> 32;

                  snmp_set_var_typed_value(
                    request->requestvb,
                    ASN_COUNTER64,
                    reinterpret_cast<const u_char*>(&c64),
                    sizeof(c64));
                  break;
                }
                case COLUMN_INDEX:
                case COLUMN_RUNNINGCOUNT:
                    snmp_set_var_typed_integer(request->requestvb, ASN_COUNTER,
                                               val.toInt());

                    break;
                default:
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHOBJECT);
                    break;
                }
            }
            break;
        }
    }
    catch(const std::exception& err)
    {
        const std::string msg =
            std::string("Error during in table_handler(): ") +
            err.what() + "\n";
        DEBUGMSGTL((SNMPID.c_str(), "%s",  msg.c_str()));
        return SNMP_ERR_GENERR;
    }
    catch(...)
    {
        DEBUGMSGTL((SNMPID.c_str(), "%s",
                    "Unknown error in table_handler()\n"));
        return SNMP_ERR_GENERR;
    }


    return SNMP_ERR_NOERROR;
}