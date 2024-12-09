inline void byteswap_slice_header(slice_header_t* slice_header) {
    // Byteswap the fields of slice_header
    slice_header->first_mb_in_slice = bswap_32(slice_header->first_mb_in_slice);
    slice_header->frame_num = bswap_32(slice_header->frame_num);
    slice_header->idr_pic_id = bswap_16(slice_header->idr_pic_id);
    slice_header->pic_order_cnt_lsb = bswap_16(slice_header->pic_order_cnt_lsb);
    slice_header->delta_pic_order_cnt_bottom = bswap_32(slice_header->delta_pic_order_cnt_bottom);
    slice_header->delta_pic_order_cnt[0] = bswap_32(slice_header->delta_pic_order_cnt[0]);
    slice_header->delta_pic_order_cnt[1] = bswap_32(slice_header->delta_pic_order_cnt[1]);
}