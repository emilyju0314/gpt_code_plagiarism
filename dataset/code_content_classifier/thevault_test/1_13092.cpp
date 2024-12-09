void Translator::SortOutputs()
{
    sort(outputBuf->items, outputBuf->items + outputBuf->count,
        [](void* a, void* b) {
            return ((Sample*)(a))->index <
                   ((Sample*)(b))->index;
        });
}