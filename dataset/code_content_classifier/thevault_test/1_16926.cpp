int GammaHNSW::SearchFromCandidates(
  DistanceComputer& qdis, int k,
  idx_t *I, float *D,
  MinimaxHeap& candidates,
  int level, const char * docids_bitmap,
  MultiRangeQueryResults *range_query_result,
  int nres_in) const
{
  std::set<int> visited_node;

  int nres = nres_in;
  int ndis = 0;
  for (int i = 0; i < candidates.size(); i++) {
    idx_t v1 = candidates.ids[i];
    float d = candidates.dis[i];
    FAISS_ASSERT(v1 >= 0);
    if (nres < k) {
      faiss::maxheap_push(++nres, D, I, d, v1);
    } else if (d < D[0]) {
      faiss::maxheap_pop(nres--, D, I);
      faiss::maxheap_push(++nres, D, I, d, v1);
    }
    visited_node.insert(v1);
  }

  bool do_dis_check = check_relative_distance;
  int nstep = 0;

  while (candidates.size() > 0) {
    float d0 = 0;
    int v0 = candidates.pop_min(&d0);

    if (do_dis_check) {
      // tricky stopping condition: there are more that ef
      // distances that are processed already that are smaller
      // than d0

      int n_dis_below = candidates.count_below(d0);
      if(n_dis_below >= efSearch) {
        break;
      }
    }

    size_t begin, end;
    neighbor_range(v0, level, &begin, &end);

    for (size_t j = begin; j < end; j++) {
      int v1 = neighbors[j];
      if (v1 < 0) break;
      if (bitmap::test(docids_bitmap, v1) ||
          (range_query_result && 
            not range_query_result->Has(v1))) {
        continue;
      }
      if (visited_node.count(v1)) {
        continue;
      }
      visited_node.insert(v1);
      ndis++;
      float d = qdis(v1);
      if (nres < k) {
        faiss::maxheap_push(++nres, D, I, d, v1);
      } else if (d < D[0]) {
        faiss::maxheap_pop(nres--, D, I);
        faiss::maxheap_push(++nres, D, I, d, v1);
      }
      candidates.push(v1, d);
    }

    nstep++;
    if (!do_dis_check && nstep > efSearch) {
      break;
    }
  }

  return nres;
}