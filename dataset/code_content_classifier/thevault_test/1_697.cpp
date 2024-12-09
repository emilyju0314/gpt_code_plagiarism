void convertMillisecons(int time, int* h, int* m, int* s, int* ms)
{
    *ms = time % 1000;
    *s = (time / 1000) % 60;
    *m = (time / 60000) % 60;
    *h = (time / 3600000);
}