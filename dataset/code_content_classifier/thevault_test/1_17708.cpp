Status LoopDataFile(int test_data_pb_fd, AllocatorPtr allocator,
                    const std::vector<onnx::ValueInfoProto> value_info, onnxruntime::NameMLValMap& name_data_map, std::ostringstream& oss) {
  google::protobuf::io::FileInputStream f(test_data_pb_fd);
  f.SetCloseOnDelete(true);
  google::protobuf::io::CodedInputStream coded_input(&f);
  bool clean_eof = false;
  Status st;
  int item_id = 1;
  for (proto::TraditionalMLData data; google::protobuf::util::ParseDelimitedFromCodedStream(&data, &coded_input, &clean_eof); ++item_id, data.Clear()) {
    MLValue value;
    switch (data.values_case()) {
      case proto::TraditionalMLData::kVectorMapStringToFloat:
        st = RichTypeProtoToMLValue<decltype(data.vector_map_string_to_float().v()), VectorMapStringToFloat>(data.vector_map_string_to_float().v(), value);
        break;
      case proto::TraditionalMLData::kVectorMapInt64ToFloat:
        st = RichTypeProtoToMLValue<decltype(data.vector_map_int64_to_float().v()), VectorMapInt64ToFloat>(data.vector_map_int64_to_float().v(), value);
        break;
      case proto::TraditionalMLData::kMapStringToString:
        st = RichTypeProtoToMLValue<decltype(data.map_string_to_string().v()), MapStringToString>(data.map_string_to_string().v(), value);
        break;
      case proto::TraditionalMLData::kMapStringToInt64:
        st = RichTypeProtoToMLValue<decltype(data.map_string_to_int64().v()), MapStringToInt64>(data.map_string_to_int64().v(), value);
        break;
      case proto::TraditionalMLData::kMapStringToFloat:
        st = RichTypeProtoToMLValue<decltype(data.map_string_to_float().v()), MapStringToFloat>(data.map_string_to_float().v(), value);
        break;
      case proto::TraditionalMLData::kMapStringToDouble:
        st = RichTypeProtoToMLValue<decltype(data.map_string_to_double().v()), MapStringToDouble>(data.map_string_to_double().v(), value);
        break;
      case proto::TraditionalMLData::kMapInt64ToString:
        st = RichTypeProtoToMLValue<decltype(data.map_int64_to_string().v()), MapInt64ToString>(data.map_int64_to_string().v(), value);
        break;
      case proto::TraditionalMLData::kMapInt64ToInt64:
        st = RichTypeProtoToMLValue<decltype(data.map_int64_to_int64().v()), MapInt64ToInt64>(data.map_int64_to_int64().v(), value);
        break;
      case proto::TraditionalMLData::kMapInt64ToFloat:
        st = RichTypeProtoToMLValue<decltype(data.map_int64_to_float().v()), MapInt64ToFloat>(data.map_int64_to_float().v(), value);
        break;
      case proto::TraditionalMLData::kMapInt64ToDouble:
        st = RichTypeProtoToMLValue<decltype(data.map_int64_to_double().v()), MapInt64ToDouble>(data.map_int64_to_double().v(), value);
        break;
      case proto::TraditionalMLData::kTensor:
        st = utils::TensorProtoToMLValue(data.tensor(), allocator, nullptr, 0, value);
        break;
      default:
        st = Status(ONNXRUNTIME, NOT_IMPLEMENTED, "unknown data type inside TraditionalMLData");
    }
    if (!st.IsOK()) break;
    if (!data.debug_info().empty()) {
      oss << ":" << data.debug_info();
    }
    std::string value_name = data.name();
    if (value_name.empty())
      value_name = value_info[name_data_map.size()].name();

    auto pv = name_data_map.insert(std::make_pair(value_name, value));
    if (!pv.second) {
      st = Status(ONNXRUNTIME, FAIL, "duplicated test data name");
      break;
    }
  }
  if (!st.IsOK()) return ORT_MAKE_STATUS(ONNXRUNTIME, FAIL, "load the ", item_id, "-th item failed,", st.ErrorMessage());
  if (!clean_eof) {
    return ORT_MAKE_STATUS(ONNXRUNTIME, FAIL, "parse input file failed, has extra unparsed data");
  }
  return Status::OK();
}