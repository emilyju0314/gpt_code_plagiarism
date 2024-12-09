int
calibrate_left( PtWidget_t *widget, ApInfo_t *apinfo, PtCallbackInfo_t *cbinfo )
{
	printf ("calibrating the left arm...\n");

	for (int j = LEFTMINAXIS; j <= LEFTMAXAXIS; j++)
	{
		arm->TorqueCalibration (j);
		arm->TrustDefaultLimits (j);
		arm->EnableAxis (j);
	}

	// enable torque readings.
	// Doesn't work. Too slow.
	//arm->EnableTorque ();

	int jnt = read_integer_from_widget (ABW_base_axis_number);
	if (jnt < LEFTMINAXIS || jnt > LEFTMAXAXIS)
		return (Pt_CONTINUE);

	int16 prop, der, shift;
	arm->GetMEIGain (jnt, DF_SHIFT, &shift);
	arm->GetMEIGain (jnt, DF_P, &prop);
	arm->GetMEIGain (jnt, DF_D, &der);

	PtArg_t arg;
	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, shift, 0);
	PtSetResources (ABW_base_gain_shift, 1, &arg);

	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, prop, 0);
	PtSetResources (ABW_base_gain_mprop, 1, &arg);

	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, der, 0);
	PtSetResources (ABW_base_gain_mder, 1, &arg);

	double p,d,i,l;

	arm->GetPositionGain (jnt, PROPORTIONAL, &p);
	arm->GetPositionGain (jnt, DERIVATIVE, &d);
	arm->GetPositionGain (jnt, INTEGRAL, &i);
	arm->GetPositionGain (jnt, INTEGRAL_LIMIT, &l);

	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, &p, 0);
	PtSetResources (ABW_base_gain_pprop, 1, &arg);
	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, &d, 0);
	PtSetResources (ABW_base_gain_pder, 1, &arg);
	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, &i, 0);
	PtSetResources (ABW_base_gain_pint, 1, &arg);
	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, &l, 0);
	PtSetResources (ABW_base_gain_plim, 1, &arg);

	// set also the current position.
	double pos = 0;
	arm->GetPosition (jnt, &pos);

	int ipos = int (pos+.5);
	PtSetArg (&arg, Pt_ARG_NUMERIC_VALUE, ipos, 0);
	PtSetResources (ABW_base_duration, 1, &arg);

	/* eliminate 'unreferenced' warnings */
	widget = widget, apinfo = apinfo, cbinfo = cbinfo;

	return( Pt_CONTINUE );
}