void FrameLoaderClientImpl::redirectDataToPlugin(Widget* pluginWidget)
{
    if (pluginWidget->isPluginContainer())
        m_pluginWidget = static_cast<WebPluginContainerImpl*>(pluginWidget);
    ASSERT(m_pluginWidget.get());
}