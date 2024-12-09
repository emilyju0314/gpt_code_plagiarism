void DrawingDemo::Run() {
  for (int i = 0; ; i++) {
    if (!PumpEvents())
      break;
    PSContext2DGetBuffer(ps_context_);
    Update();
    PSContext2DSwapBuffer(ps_context_);
    printf("Frame: %04d\b\b\b\b\b\b\b\b\b\b\b", i);
    fflush(stdout);
  }

  printf("\nDone\n");
}