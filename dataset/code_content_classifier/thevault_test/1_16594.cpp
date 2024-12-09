void DumpRenderTreeSupportGtk::dumpConfigurationForViewport(WebKitWebView* webView, gint deviceDPI, gint deviceWidth, gint deviceHeight, gint availableWidth, gint availableHeight)
{
    g_return_if_fail(WEBKIT_IS_WEB_VIEW(webView));

    ViewportArguments arguments = webView->priv->corePage->mainFrame()->document()->viewportArguments();
    ViewportAttributes attrs = computeViewportAttributes(arguments, /* default layout width for non-mobile pages */ 980, deviceWidth, deviceHeight, deviceDPI, IntSize(availableWidth, availableHeight));

    fprintf(stdout, "viewport size %dx%d scale %f with limits [%f, %f] and userScalable %f\n", attrs.layoutSize.width(), attrs.layoutSize.height(), attrs.initialScale, attrs.minimumScale, attrs.maximumScale, attrs.userScalable);
}