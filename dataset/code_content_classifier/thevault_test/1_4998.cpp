TEST(FormatPrintfTemplateAndSet, NullPointer) {
  FormatPrintfTemplateAndSet(/*output_string=*/nullptr, /*format=*/"");
  FormatPrintfTemplateAndSet(/*output_string=*/nullptr, "%d", 123);
  FormatPrintfTemplateAndSet(/*output_string=*/nullptr, "string=%s int=%d",
                             "foo", 123);
}