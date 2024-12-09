size_t scan_one_list(GammaInvertedListScanner *scanner, idx_t key, 
    float coarse_dis_i, float *simi, idx_t *idxi, int k, 
    idx_t nlist, faiss::InvertedLists *invlists, 
    bool store_pairs, bool ivf_flat, float *raw_vec_head = nullptr) {
  if (key < 0) {
    // not enough centroids for multiprobe
    return 0;
  }
  if (key >= (idx_t) nlist) {
    LOG(INFO) << "Invalid key=" << key << ", nlist=" << nlist;
    return 0;
  }

  size_t list_size = invlists->list_size(key);

  // don't waste time on empty lists
  if (list_size == 0) {
      return 0;
  }

  std::unique_ptr<faiss::InvertedLists::ScopedIds> sids;
  const idx_t *ids = nullptr;

  if (!store_pairs) {
    sids.reset (new faiss::InvertedLists::ScopedIds (invlists, key));
    ids = sids->get();
  }

  scanner->set_list(key, coarse_dis_i);
  
  //scan_codes need uint8_t *
  const uint8_t *codes = nullptr;
  
  if(ivf_flat) {
    codes = reinterpret_cast<uint8_t *>(raw_vec_head);
  } else {
    faiss::InvertedLists::ScopedCodes scodes(invlists, key);
    codes = scodes.get(); 
  }
  scanner->scan_codes(list_size, codes, ids, simi, idxi, k);

  return list_size;
}