std::shared_ptr<Bag<uml::Classifier>> ExceptionHandlerImpl::getExceptionType() const
{
	if(m_exceptionType == nullptr)
	{
		m_exceptionType.reset(new Bag<uml::Classifier>());
		
		
	}
//assert(m_exceptionType);
    return m_exceptionType;
}