void sli_ui32_print_ts(uint32_t n)
{
  if (n < 1000) {
    printf ("%ld", n);
    return;
  }
  sli_ui32_print_ts(n / 1000);
  printf (",%03ld", n % 1000);
}