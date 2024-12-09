bool GLSLShader::CheckIfIsDefined(const char* attributeName) const
    {
        // get the number of defines and iterate through them
        return AZStd::any_of(begin(m_defines), end(m_defines), [attributeName](const AZStd::string& define)
        {
            return AzFramework::StringFunc::Equal(define.c_str(), attributeName, false /* no case */);
        });
    }