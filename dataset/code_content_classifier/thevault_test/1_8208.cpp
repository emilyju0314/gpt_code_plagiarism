double PID::compute(double input)
{
    double dinput = (input - last_input);
    return compute_output(input, dinput);
}