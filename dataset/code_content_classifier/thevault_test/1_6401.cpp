unsigned char* cutImage(int x, int y, int w, int h, unsigned char *data, 
				   int &iWidth, int &iHeight, bool deleteData)
{
   int i,j;
   byte *newData = new byte[w*h];

   memset(newData, 0, w*h);

   byte *ptr1, *ptr2;

   ptr1 = newData;

   for (i = 0; i < h; i++)
   {
     if ((y+i)>=iHeight || (y+i)<=0) continue;
     ptr2 = data + x + (i+y)*iWidth;

	 if ((i+y)<iHeight && (i+y)>=0)
       for (j = 0; j < w; j++)
	   {
		 if ((j+x)>=0 && (j+x)<iWidth) *ptr1 = *ptr2;
		 ptr1++;
		 ptr2++;
	   }
   }

   iWidth = w;
   iHeight = h;
   if (deleteData) delete []data;
   return newData;
}