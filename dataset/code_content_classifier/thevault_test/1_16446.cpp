const Eina_Rectangle* ewk_view_repaints_get(const Ewk_View_Private_Data* priv, size_t* count)
{
    EINA_SAFETY_ON_NULL_RETURN_VAL(count, 0);
    if (count)
        *count = 0;
    EINA_SAFETY_ON_NULL_RETURN_VAL(priv, 0);
    if (count)
        *count = priv->repaints.count;
    return priv->repaints.array;
}