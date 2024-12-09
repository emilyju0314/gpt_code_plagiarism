void SubroutineDCTvector(float *FirstIn, int StepIn, float *FirstOut, int StepOut)
{
	float X07P = FirstIn[0*StepIn] + FirstIn[7*StepIn];
	float X16P = FirstIn[1*StepIn] + FirstIn[6*StepIn];
	float X25P = FirstIn[2*StepIn] + FirstIn[5*StepIn];
	float X34P = FirstIn[3*StepIn] + FirstIn[4*StepIn];

	float X07M = FirstIn[0*StepIn] - FirstIn[7*StepIn];
	float X61M = FirstIn[6*StepIn] - FirstIn[1*StepIn];
	float X25M = FirstIn[2*StepIn] - FirstIn[5*StepIn];
	float X43M = FirstIn[4*StepIn] - FirstIn[3*StepIn];

	float X07P34PP = X07P + X34P;
	float X07P34PM = X07P - X34P;
	float X16P25PP = X16P + X25P;
	float X16P25PM = X16P - X25P;

	FirstOut[0*StepOut] = C_norm * (X07P34PP + X16P25PP);
	FirstOut[2*StepOut] = C_norm * (C_b * X07P34PM + C_e * X16P25PM);
	FirstOut[4*StepOut] = C_norm * (X07P34PP - X16P25PP);
	FirstOut[6*StepOut] = C_norm * (C_e * X07P34PM - C_b * X16P25PM);

	FirstOut[1*StepOut] = C_norm * (C_a * X07M - C_c * X61M + C_d * X25M - C_f * X43M);
	FirstOut[3*StepOut] = C_norm * (C_c * X07M + C_f * X61M - C_a * X25M + C_d * X43M);
	FirstOut[5*StepOut] = C_norm * (C_d * X07M + C_a * X61M + C_f * X25M - C_c * X43M);
	FirstOut[7*StepOut] = C_norm * (C_f * X07M + C_d * X61M + C_c * X25M + C_a * X43M);
}