float* func_returning_array(int *n)
{
    int some_number = 20;
    *n = some_number;

    float* f = (float *)calloc(some_number,sizeof(float));
    assert(f != NULL);

    return f;
}