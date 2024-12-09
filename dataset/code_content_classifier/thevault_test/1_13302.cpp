const std::string StatCommand::getBrokenCount(const InputInfoPtr& info) const
{
    InThreadPtr inthread = getInThread(info);

    std::string result;
    try
    {
        const u_long count = inthread->getReader()->getBrokenCount();
        result = boost::lexical_cast<std::string>(count);
    }
    catch(const Exception&)
    {
        result = NOTAVAILABLE;
    }
    catch(const boost::bad_lexical_cast&)
    {
        throw Exception(__FILE__, __LINE__, err::BADLEXCAST);
    }

    return result;
}