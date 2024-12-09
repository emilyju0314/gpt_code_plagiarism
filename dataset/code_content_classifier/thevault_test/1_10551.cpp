static LIST ClusterOneConfig(int shape_id, const char *class_label, LIST mf_classes,
                             const ShapeTable &shape_table, MasterTrainer *trainer) {
  int num_samples;
  CLUSTERER *clusterer =
      trainer->SetupForClustering(shape_table, feature_defs, shape_id, &num_samples);
  Config.MagicSamples = num_samples;
  LIST proto_list = ClusterSamples(clusterer, &Config);
  CleanUpUnusedData(proto_list);

  // Merge protos where reasonable to make more of them significant by
  // representing almost all samples of the class/font.
  MergeInsignificantProtos(proto_list, class_label, clusterer, &Config);
#ifndef GRAPHICS_DISABLED
  if (strcmp(FLAGS_test_ch.c_str(), class_label) == 0) {
    DisplayProtoList(FLAGS_test_ch.c_str(), proto_list);
  }
#endif // !GRAPHICS_DISABLED
  // Delete the protos that will not be used in the inttemp output file.
  proto_list = RemoveInsignificantProtos(proto_list, true, false, clusterer->SampleSize);
  FreeClusterer(clusterer);
  MERGE_CLASS merge_class = FindClass(mf_classes, class_label);
  if (merge_class == nullptr) {
    merge_class = new MERGE_CLASS_NODE(class_label);
    mf_classes = push(mf_classes, merge_class);
  }
  int config_id = AddConfigToClass(merge_class->Class);
  merge_class->Class->font_set.push_back(shape_id);
  LIST proto_it = proto_list;
  iterate(proto_it) {
    auto *prototype = reinterpret_cast<PROTOTYPE *>(proto_it->first_node());
    // See if proto can be approximated by existing proto.
    int p_id = FindClosestExistingProto(merge_class->Class, merge_class->NumMerged, prototype);
    if (p_id == NO_PROTO) {
      // Need to make a new proto, as it doesn't match anything.
      p_id = AddProtoToClass(merge_class->Class);
      MakeNewFromOld(ProtoIn(merge_class->Class, p_id), prototype);
      merge_class->NumMerged[p_id] = 1;
    } else {
      PROTO_STRUCT dummy_proto;
      MakeNewFromOld(&dummy_proto, prototype);
      // Merge with the similar proto.
      ComputeMergedProto(ProtoIn(merge_class->Class, p_id), &dummy_proto,
                         static_cast<float>(merge_class->NumMerged[p_id]), 1.0,
                         ProtoIn(merge_class->Class, p_id));
      merge_class->NumMerged[p_id]++;
    }
    AddProtoToConfig(p_id, merge_class->Class->Configurations[config_id]);
  }
  FreeProtoList(&proto_list);
  return mf_classes;
}