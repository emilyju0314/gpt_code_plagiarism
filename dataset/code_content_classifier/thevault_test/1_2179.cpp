void 
rsm::breakpoint1()
{
  if (break1) {
    tprintf("Dying at breakpoint 1 in rsm!\n");
    exit(1);
  }
}