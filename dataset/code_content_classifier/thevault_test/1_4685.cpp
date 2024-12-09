std::string SamplingReportDataView::GetValueForCopy(int row, int column) {
  const SampledFunction& func = GetSampledFunction(row);
  switch (column) {
    case kColumnInclusive:
      return absl::StrFormat("%.2f%%", func.inclusive_percent);
    case kColumnExclusive:
      return absl::StrFormat("%.2f%%", func.exclusive_percent);
    case kColumnUnwindErrors:
      return (func.unwind_errors > 0) ? absl::StrFormat("%.2f%%", func.unwind_errors_percent) : "";
    default:
      return GetValue(row, column);
  }
}