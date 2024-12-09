inline DescriptorFrame(uint32_t frame_id, const Channels& channels)
      : _frame_id(frame_id), _channels(channels)
  {
    assert( !_channels.empty() );

    _max_rows = _channels[0].rows() - 1;
    _max_cols = _channels[0].cols() - 1;

    _gradients.resize( _channels.size() );
    for(size_t i = 0; i < _channels.size(); ++i) {
      _gradients[i].compute(_channels[i]);
    }
  }