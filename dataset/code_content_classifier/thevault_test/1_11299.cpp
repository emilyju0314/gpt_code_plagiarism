sframe_iterator(
      const std::vector<std::shared_ptr<sarray_reader<flexible_type> > > &data,
      size_t segmentid,
      bool is_begin_iterator) : _data(&data),
    _segmentid(segmentid) {

      // Create an SArray iterator for each column of the SFrame.
      cur_iter.resize(_data->size());
      cur_element.resize(_data->size());
      for(size_t i = 0; i < _data->size(); ++i) {
        if(is_begin_iterator) {
          cur_iter[i] = _data->at(i)->begin(segmentid);
        } else {
          cur_iter[i] = _data->at(i)->end(segmentid);
        }
      }

      // Variables that make equality easier to check
      segment_limit = _data->at(0)->segment_length(segmentid);

      if(is_begin_iterator) {
        cur_segment_pos = 0;
      } else {
        cur_segment_pos = segment_limit;
      }
    }