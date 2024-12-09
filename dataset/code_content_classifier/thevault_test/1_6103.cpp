void SegmenterMS::convert_RGB_LUV( RasterIpChannels* signal, long selects )
{
  int x, y, z, my_temp;
  
  float l_star, u_star, v_star;
  float u_prime, v_prime;
  register int temp_col, temp_index, temp_ind;
  register int j,k;
  
  int a00=XYZ[0][0], a01=XYZ[0][1], a02=XYZ[0][2];
  int a10=XYZ[1][0], a11=XYZ[1][1], a12=XYZ[1][2];
  int a20=XYZ[2][0], a21=XYZ[2][1], a22=XYZ[2][2];
  
  int *A00 = new int[MAXV]; int *A01 = new int[MAXV]; int *A02 = new int[MAXV];
  int *A10 = new int[MAXV]; int *A11 = new int[MAXV]; int *A12 = new int[MAXV];
  int *A20 = new int[MAXV]; int *A21 = new int[MAXV]; int *A22 = new int[MAXV];
  
  for(j=0; j<MAXV;j++)
    {
      A00[j]=a00*j; A01[j]=a01*j; A02[j]=a02*j;
      A10[j]=a10*j; A11[j]=a11*j; A12[j]=a12*j;
      A20[j]=a20*j; A21[j]=a21*j; A22[j]=a22*j;
    }
 
  float *my_pow = new float[MAXV];
  for(j=0; j<MAXV;j++)
    my_pow[j]= 116.0 * pow(j/255.0, 0.3333333) - 16;
 
  Octet* temp_ch0 = signal->chdata(0);
  Octet* temp_ch1 = signal->chdata(1);
  Octet* temp_ch2 = signal->chdata(2);

  int pp;    
  int *temp0, *temp1, *temp2;
  pp = _p_ptr;
  if ( selects & Lightness ) temp0 = _data_all[pp++];
  if ( selects & Ustar ) temp1 = _data_all[pp++];
  if ( selects & Vstar ) temp2 = _data_all[pp++]; 
  _p_ptr=pp;

  for ( j = 0; j < _n_colors; j++)
    {
        temp_col=_col_RGB[j];
	int R=temp_col>>16; int G=(temp_col>>8) & 255; int B=temp_col & 255;

        x = A00[R] + A01[G] + A02[B];
        y = A10[R] + A11[G] + A12[B];
        z = A20[R] + A21[G] + A22[B];
	
        float  tval = y / 2550000.0; //Yn==1
	if ( tval >  Lt)  l_star = my_pow[(int)(tval*255+0.5)];
        else  l_star = 903.3 * tval;

        my_temp = x + 15 * y + 3 * z;
	if(my_temp)
	  {
	    u_prime = (float)(x << 2) / (float)(my_temp);
	    v_prime = (float)(9 * y) / (float)(my_temp);
	  }
	else
	  {
	    u_prime=4.0;
	    v_prime=9.0/15.0;
	  }
	
	tval=13*l_star;
        u_star = tval* (u_prime - Un_prime); // Un_prime = 0.1978
        v_star = tval* (v_prime - Vn_prime); // Vn_prime = 0.4683

	_col0[j] = (int)(l_star+0.5);
	if(u_star>0) _col1[j] = (int)(u_star+0.5);
        else _col1[j] = (int)(u_star-0.5);
  
	if(v_star>0) _col2[j] = (int)(v_star+0.5);
        else _col2[j] = (int)(v_star-0.5);
    }
  for(j=0;j<_ro_col;j++)
    {
      temp_col=(((((int)temp_ch0[j])<<8)+(int)temp_ch1[j])<<8)+(int)temp_ch2[j];
      temp_ind=_col_misc[temp_col>>6];
      for(k=temp_ind;k<temp_ind+SEC_SIZE;k++)
	if(_col_RGB[k]==temp_col)
	  {
           temp_index=_col_index[j]=k;
           break;
	 }
      temp0[j]=_col0[temp_index];
      temp1[j]=_col1[temp_index];
      temp2[j]=_col2[temp_index];
    }   
  delete [] my_pow;
  delete [] A22; delete [] A21; delete [] A20;
  delete [] A12; delete [] A11; delete [] A10;
  delete [] A02; delete [] A01; delete [] A00;
  delete [] _col_misc;
  delete [] _col_RGB;
  //cerr<<":";
}