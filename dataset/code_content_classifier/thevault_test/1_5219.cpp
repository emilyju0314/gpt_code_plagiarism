ts::CountryAvailabilityDescriptor::CountryAvailabilityDescriptor(bool availability, const std::initializer_list<UString> countries) :
    AbstractDescriptor(MY_DID, MY_XML_NAME, MY_STD, 0),
    country_availability(availability),
    country_codes(countries)
{
    _is_valid = true;
}