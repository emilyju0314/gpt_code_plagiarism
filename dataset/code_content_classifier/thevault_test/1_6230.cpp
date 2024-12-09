static int ApplyRG(Image<int>& src, Image<int>& dest)
{
  static Image<int> xstack;
  static Image<int> ystack;
  int i, j;
  int ii, jj;
  int id = 1;
  int top = 0;
  int maxCount = 0;
  int maxCountId = 0;
  int count;
  int h = src.GetHeight();
  int w = src.GetWidth();
  xstack.Create(h*w*4,1);
  ystack.Create(h*w*4,1);

  for (i=0; i<h; i++)
    {
      for (j=0; j<w; j++)
	{
	  dest(i,j) = (src(i,j)==0);
	}
    }
  for (i=0; i<h; i++)
    {
      for (j=0; j<w; j++)
	{
	  if (dest(i,j) == 0)
	    {
	      id++;
	      /*
	      if (id>255)
		{
		  id = 2;
		}
	       */
	      count = 0;
	      top = 1;
	      ystack(0,0) = i;
	      xstack(0,0) = j;
	      while (top>0)
		{
		  top--;
		  ii = ystack(top,0);
		  jj = xstack(top,0);
		  if (dest(ii,jj) == 0)
		    {
		      dest(ii,jj) = id;
		      count++;
		      if (ii>0)
			{
			  if (dest(ii-1,jj) == 0)
			    {
			      ystack(top,0) = ii-1;
			      xstack(top,0) = jj;
			      top++;
			    }
			}
		      if (ii+1<h)
			{
			  if (dest(ii+1,jj) == 0)
			    {
			      ystack(top,0) = ii+1;
			      xstack(top,0) = jj;
			      top++;
			    }
			}
		      if (jj>0)
			{
			  if (dest(ii,jj-1) == 0)
			    {
			      ystack(top,0) = ii;
			      xstack(top,0) = jj-1;
			      top++;
			    }
			}
		      if (jj+1<w)
			{
			  if (dest(ii,jj+1) == 0)
			    {
			      ystack(top,0) = ii;
			      xstack(top,0) = jj+1;
			      top++;
			    }
			}
		    }
		}
	      if (count>maxCount)
		{
		  maxCount = count;
		  maxCountId = id;
		}
	    }
	}
    }
  bestId = maxCountId;
  return maxCountId;
}