static ScrollingCoordinator* scrollingCoordinatorFromLayer(PaintLayer& layer)
{
    Page* page = layer.layoutObject()->frame()->page();
    return (!page) ? nullptr : page->scrollingCoordinator();
}