Configuration *Configuration::LoggingFn(LoggingFunction fn)
{
	loggingFunction = fn;

	return this;
}