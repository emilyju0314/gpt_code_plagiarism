JaniceError janice_io_opencv_create_frommat(std::vector<cv::Mat> ims, JaniceMediaIterator *_it)
{
    JaniceMediaIterator it = new JaniceMediaIteratorType();

    it->is_video = &is_video;
    it->get_frame_rate =  &get_frame_rate;

    it->next = &next;
    it->seek = &seek;
    it->get  = &get;
    it->tell = &tell;

    it->free_image = &free_image;
    it->free       = &free_iterator;

    it->reset      = &reset;

    JaniceMediaIteratorStateTypeFM* state = new JaniceMediaIteratorStateTypeFM();
    for (auto im : ims){
        JaniceImage jim;
        cv_mat_to_janice_image(im, &jim);
        state->images.push_back(jim);
    }
    state->pos = 0;

    it->_internal = (void*) (state);

    *_it = it;

    return JANICE_SUCCESS;
}