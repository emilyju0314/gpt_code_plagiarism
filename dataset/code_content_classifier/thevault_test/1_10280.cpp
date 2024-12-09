void
    update(entt::registry& rRegistry)
    {
        rRegistry.view<Component::Position,
                       Component::Velocity>().each([&](auto& rPosition, auto const& rVelocity)
                                                   {
                                                       rPosition.m_value[0] += rVelocity.m_delta[0];
                                                       rPosition.m_value[1] += rVelocity.m_delta[1];
                                                   });
    }