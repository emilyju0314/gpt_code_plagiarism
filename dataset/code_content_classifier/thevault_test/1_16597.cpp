Eina_Iterator* ewk_frame_children_iterator_new(Evas_Object* o)
{
    EWK_FRAME_SD_GET_OR_RETURN(o, sd, 0);
    Eina_Iterator_Ewk_Frame* it = (Eina_Iterator_Ewk_Frame*)
        calloc(1, sizeof(Eina_Iterator_Ewk_Frame));
    if (!it)
        return 0;

    EINA_MAGIC_SET(&it->base, EINA_MAGIC_ITERATOR);
    it->base.next = FUNC_ITERATOR_NEXT(_ewk_frame_children_iterator_next);
    it->base.get_container = FUNC_ITERATOR_GET_CONTAINER(_ewk_frame_children_iterator_get_container);
    it->base.free = FUNC_ITERATOR_FREE(free);
    it->obj = o;
    return &it->base;
}