WebKitWebHistoryItem* webkit_web_history_item_new_with_data(const gchar* uri, const gchar* title)
{
    WebKitWebHistoryItem* webHistoryItem = WEBKIT_WEB_HISTORY_ITEM(g_object_new(WEBKIT_TYPE_WEB_HISTORY_ITEM, NULL));
    WebKitWebHistoryItemPrivate* priv = webHistoryItem->priv;

    WebCore::KURL historyUri(WebCore::KURL(), uri);
    WTF::String historyTitle = WTF::String::fromUTF8(title);
    RefPtr<WebCore::HistoryItem> item = WebCore::HistoryItem::create(historyUri, historyTitle, 0);
    priv->historyItem = item.release().releaseRef();
    webkit_history_item_add(webHistoryItem, priv->historyItem);

    return webHistoryItem;
}