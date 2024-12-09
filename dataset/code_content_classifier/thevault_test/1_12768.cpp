inline quater toBaseR(SE3 const& m)
{
	/*	matrix4 out;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			out.m[i][j]=m(i,j);

	quater q;
	q.setRotation(out);*/

	quater q;
	m_real tr, s;
    int    i, j, k;
    static int next[3] = { 1, 2, 0 };

    tr = m(0,0) + m(1,1) + m(2,2);
    if ( tr > 0.0 )
    {
        s = sqrt( tr + 1.0 );
        q[0] = ( s * 0.5 );
        s = 0.5 / s;
        q.x = ( m(2,1) - m(1,2) ) * s;
        q.y = ( m(0,2) - m(2,0) ) * s;
        q.z = ( m(1,0) - m(0,1) ) * s;
    }
    else
    {
        i = 0;
        if ( m(1,1) > m(0,0) ) i = 1;
        if ( m(2,2) > m(i,i) ) i = 2;

        j = next[i];
        k = next[j];

        s = sqrt( (m(i,i)
				   - (m(j,j) + m(k,k))) + 1.0 );
        q[i+1] = s * 0.5;
        s = 0.5 / s;
        q.w   = ( m(k,j) - m(j,k) ) * s;
        q[j+1] = ( m(j,i) + m(i,j) ) * s;
        q[k+1] = ( m(k,i) + m(i,k) ) * s;
    }

	return q;
}