EntityData::EntityData(
        const AZ::EntityId entityId,
        const AZ::Transform& worldFromLocal,
        const bool locked,
        const bool visible,
        const bool inFocus,
        const bool descendantOfClosedContainer,
        const bool selected,
        const bool iconHidden)
        : m_worldFromLocal(worldFromLocal)
        , m_entityId(entityId)
        , m_locked(locked)
        , m_visible(visible)
        , m_inFocus(inFocus)
        , m_descendantOfClosedContainer(descendantOfClosedContainer)
        , m_selected(selected)
        , m_iconHidden(iconHidden)
    {
    }