zx_status_t Ge2dTask::AllocOutputCanvasIds(
    const buffer_collection_info_2_t* output_buffer_collection,
    const image_format_2_t* output_image_format) {
  if (output_image_format->pixel_format.type != fuchsia_sysmem_PixelFormatType_NV12) {
    return ZX_ERR_NOT_SUPPORTED;
  }
  if (((output_image_format->display_height % 2) != 0) ||
      (output_image_format->bytes_per_row == 0)) {
    return ZX_ERR_INVALID_ARGS;
  }
  // Create a map from <vmo handle> -> <canvas id pair> for every output
  // buffer. We do this by allocating each output buffer, allocating a
  // canvas id pair for it, adding that to the hashmap and then freeing
  // the buffers when done.
  typedef struct buf_canvasids {
    fzl::VmoPool::Buffer output_buffer;
    image_canvas_id_t canvas_ids;
  } buf_canvas_ids_t;
  std::unique_ptr<buf_canvas_ids_t[]> buf_canvas_ids;
  fbl::AllocChecker ac;
  buf_canvas_ids = std::unique_ptr<buf_canvas_ids_t[]>(
      new (&ac) buf_canvas_ids_t[output_buffer_collection->buffer_count]);
  if (!ac.check()) {
    return ZX_ERR_NO_MEMORY;
  }
  for (uint32_t i = 0; i < output_buffer_collection->buffer_count; i++) {
    buf_canvas_ids[i].output_buffer = WriteLockOutputBuffer();
    zx_handle_t vmo_handle = buf_canvas_ids[i].output_buffer.vmo_handle();
    zx_status_t status =
        AllocCanvasId(output_image_format, vmo_handle, buf_canvas_ids[i].canvas_ids,
                      CANVAS_FLAGS_READ | CANVAS_FLAGS_WRITE);
    if (status != ZX_OK) {
      for (uint32_t j = 0; j < i; j++) {
        amlogic_canvas_free(&canvas_, buf_canvas_ids[j].canvas_ids.canvas_idx[kYComponent]);
        amlogic_canvas_free(&canvas_, buf_canvas_ids[j].canvas_ids.canvas_idx[kUVComponent]);
        ReleaseOutputBuffer(std::move(buf_canvas_ids[j].output_buffer));
      }
      return status;
    }
  }
  for (uint32_t i = 0; i < output_buffer_collection->buffer_count; i++) {
    buffer_map_[buf_canvas_ids[i].output_buffer.vmo_handle()] = buf_canvas_ids[i].canvas_ids;
    ReleaseOutputBuffer(std::move(buf_canvas_ids[i].output_buffer));
  }
  return ZX_OK;
}