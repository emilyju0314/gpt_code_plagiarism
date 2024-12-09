bool positionSlider(unsigned int x)
{
    if (x > global::state.Sx1 && x < global::state.Sx2)
    {
        if (global::state.mousePressL1)
        {
            seekToTime(float(x-global::state.Sx1)/(global::state.Sx2-global::state.Sx1));
            return 1;
        }
        else if (global::state.mousePressL2)
        {
            global::state.exposure = pow(2.0f, 20*float(x-global::state.Sx1)
                /(global::state.Sx2-global::state.Sx1) - 10);
            glUniform1f(glGetUniformLocation(global::state.dequantProg, "exposure"), global::state.exposure);
            resetGuiTime();
            glutPostRedisplay();
            return 1;
        }
    }
    
    return 0;
}