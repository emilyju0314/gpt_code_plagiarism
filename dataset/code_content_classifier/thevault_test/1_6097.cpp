YARPEurobotHeadKin::YARPEurobotHeadKin (const YMatrix &dh_left, const YMatrix &dh_right, const YHmgTrsf &bline)
	: _leftCamera (dh_left, bline),
	  _rightCamera (dh_right, bline)
{
	///
	ACE_ASSERT (dh_left.NRows() == dh_right.NRows());

	/// nFrame must be rather the NRows - the # of rows with fifth colum == 0.
	_nFrame = dh_left.NRows();

	_leftJoints.Resize (_nFrame);
	_rightJoints.Resize (_nFrame);

	_leftJoints = 0;
	_rightJoints = 0;
}