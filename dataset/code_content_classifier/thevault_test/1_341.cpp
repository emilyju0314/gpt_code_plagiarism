void Imc::EndEvaluate()
{
    if(_nframes > 0) {
        if(_block_length == 0) {
	    string suffix = string(".") + _extension;
            WriteDist(suffix);
            if(_do_imc)
                WriteIMCData();
        }
    }
    // clear interactions and groups
    _interactions.clear();
    _groups.clear();
    if(!_processed_some_frames)
        throw std::runtime_error("no frames were processed. Please check your input");
}