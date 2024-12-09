void XmlUnitTestResultPrinter::PrintXmlTestCase(FILE* out,
                                                const TestCase& test_case) {
  fprintf(out,
          "  <testsuite name=\"%s\" tests=\"%d\" failures=\"%d\" "
          "disabled=\"%d\" ",
          EscapeXmlAttribute(test_case.name()).c_str(),
          test_case.total_test_count(),
          test_case.failed_test_count(),
          test_case.disabled_test_count());
  fprintf(out,
          "errors=\"0\" time=\"%s\">\n",
          FormatTimeInMillisAsSeconds(test_case.elapsed_time()).c_str());
  for (int i = 0; i < test_case.total_test_count(); ++i) {
    StrStream stream;
    OutputXmlTestInfo(&stream, test_case.name(), *test_case.GetTestInfo(i));
    fprintf(out, "%s", StrStreamToString(&stream).c_str());
  }
  fprintf(out, "  </testsuite>\n");
}