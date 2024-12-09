JaniceError janice_io_opencv_create_sparse_media_iterator(const char** filenames, size_t num_files, JaniceMediaIterator *_it)
{
    JaniceMediaIterator it = new JaniceMediaIteratorType();

    it->is_video = &is_video;
    it->get_frame_rate =  &get_frame_rate;
    it->get_physical_frame_rate =  &get_physical_frame_rate;

    it->next = &next;
    it->seek = &seek;
    it->get  = &get;
    it->tell = &tell;
    it->physical_frame = &physical_frame;

    it->free_image = &free_image;
    it->free       = &free_iterator;

    it->reset      = &reset;

    JaniceMediaIteratorStateType* state = new JaniceMediaIteratorStateType();
    for (size_t i = 0; i < num_files; ++i) {
        state->filenames.push_back(std::string(filenames[i]));
    }
    state->pos = 0;

    it->_internal = (void*) (state);

    *_it = it;

    return JANICE_SUCCESS;
}