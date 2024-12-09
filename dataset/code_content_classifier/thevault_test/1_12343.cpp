void AnimGraphTimeCondition::GetTooltip(AZStd::string* outResult) const
    {
        AZStd::string columnName, columnValue;

        // add the condition type
        columnName = "Condition Type: ";
        columnValue = RTTI_GetTypeName();
        *outResult = AZStd::string::format("<table border=\"0\"><tr><td width=\"165\"><b>%s</b></td><td>%s</td>", columnName.c_str(), columnValue.c_str());

        // add the count down
        columnName = "Count Down: ";
        *outResult += AZStd::string::format("</tr><tr><td><b>%s</b></td><td>%.2f secs</td>", columnName.c_str(), m_countDownTime);

        // add the randomization used flag
        columnName = "Randomization Used: ";
        *outResult += AZStd::string::format("</tr><tr><td><b>%s</b></td><td>%s</td>", columnName.c_str(), m_useRandomization ? "Yes" : "No");

        // add the random count down range
        columnName = "Random Count Down Range: ";
        *outResult += AZStd::string::format("</tr><tr><td><b>%s</b></td><td>(%.2f secs, %.2f secs)</td></tr></table>", columnName.c_str(), m_minRandomTime, m_maxRandomTime);
    }