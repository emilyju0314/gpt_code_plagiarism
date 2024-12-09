PlatformContextSkia::State PlatformContextSkia::State::cloneInheritedProperties()
{
    PlatformContextSkia::State state(*this);

    // Everything is inherited except for the clip paths.
    state.m_antiAliasClipPaths.clear();

    return state;
}