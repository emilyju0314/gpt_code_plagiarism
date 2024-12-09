WebKitWebHistoryItem* webkit_web_history_item_new()
{
    WebKitWebHistoryItem* webHistoryItem = WEBKIT_WEB_HISTORY_ITEM(g_object_new(WEBKIT_TYPE_WEB_HISTORY_ITEM, NULL));
    WebKitWebHistoryItemPrivate* priv = webHistoryItem->priv;

    RefPtr<WebCore::HistoryItem> item = WebCore::HistoryItem::create();
    priv->historyItem = item.release().releaseRef();
    webkit_history_item_add(webHistoryItem, priv->historyItem);

    return webHistoryItem;
}