void node_lame_encode_buffer_async (uv_work_t *req) {
  encode_req *r = (encode_req *)req->data;

  if (r->input_type == PCM_TYPE_SHORT_INT) {
    if (r->channels > 1) {
      // encoding short int interleaved input buffer
      r->rtn = lame_encode_buffer_interleaved(
        r->gfp,
        (short int *)r->input,
        r->num_samples,
        r->output,
        r->output_size
      );
    } else {
      // encoding short int input buffer
      r->rtn = lame_encode_buffer(
        r->gfp,
        (short int *)r->input,
        NULL,
        r->num_samples,
        r->output,
        r->output_size
      );
    }
  } else if (r->input_type == PCM_TYPE_FLOAT) {
    if (r->channels > 1) {
      // encoding float interleaved input buffer
      r->rtn = lame_encode_buffer_interleaved_ieee_float(
        r->gfp,
        (float *)r->input,
        r->num_samples,
        r->output,
        r->output_size
      );
    } else {
      // encoding float input buffer
      r->rtn = lame_encode_buffer_ieee_float(
        r->gfp,
        (float *)r->input,
        NULL,
        r->num_samples,
        r->output,
        r->output_size
      );
    }
  } else if (r->input_type == PCM_TYPE_DOUBLE) {
    if (r->channels > 1) {
      // encoding double interleaved input buffer
      r->rtn = lame_encode_buffer_interleaved_ieee_double(
        r->gfp,
        (double *)r->input,
        r->num_samples,
        r->output,
        r->output_size
      );
    } else {
      // encoding double input buffer
      r->rtn = lame_encode_buffer_ieee_double(
        r->gfp,
        (double *)r->input,
        NULL,
        r->num_samples,
        r->output,
        r->output_size
      );
    }
  }
}