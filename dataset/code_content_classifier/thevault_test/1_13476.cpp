InputInfo::InputInfo(const RouteInfoPtr& route) :
    mod::Info(route->getUUID(), route->getName()),
    m_route(route), m_path(), m_mname(), m_muuid()
{
    BOOST_ASSERT(m_route.getValue());
}