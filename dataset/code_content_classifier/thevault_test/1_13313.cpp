Result TrapInfo::add2PDU(netsnmp_pdu* pdu) const
{
    CHECKNOTNULL(pdu);

    // Generic trap number
    // A number in the range 0-6.
    // The true generic traps have numbers 0-5;
    //if you're sending an enterprise-specific trap, set this number to 6
    pdu->trap_type = 6;

    // Specific trap number
    // A number indicating the specific trap you want to send.
    // If you're sending a generic trap, this parameter is
    // ignoredyou're probably better off setting it to zero.
    // If you're sending a specific trap, the trap number is up to you.
    // For example, if you send a trap with the OID
    //.1.3.6.1.4.1.2500.3003.0, 3003 is the specific trap number.
    pdu->specific_type = m_oid[m_oid_len - 1];

    pdu->enterprise = static_cast<oid*>(calloc(m_oid_len, sizeof(oid)));
    memcpy(pdu->enterprise, m_oid, m_oid_len * sizeof(oid));
    pdu->enterprise_length = m_oid_len;

    if (snmp_add_var(pdu, m_oid, m_oid_len, m_type, m_value.c_str()))
    {
        klk_log(KLKLOG_ERROR,
                "Failed to add trap value to PDU. Type: '%c'; Value: '%s'",
                m_type, m_value.c_str());
        return ERROR;
    }

    return OK;
}