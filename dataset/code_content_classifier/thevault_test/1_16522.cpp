gdouble webkit_web_history_item_get_last_visited_time(WebKitWebHistoryItem* webHistoryItem)
{
    g_return_val_if_fail(WEBKIT_IS_WEB_HISTORY_ITEM(webHistoryItem), 0);

    WebCore::HistoryItem* item = core(WEBKIT_WEB_HISTORY_ITEM(webHistoryItem));

    g_return_val_if_fail(item, 0);

    return item->lastVisitedTime();
}