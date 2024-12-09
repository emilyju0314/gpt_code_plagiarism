SDoublePlane find_edges(const SDoublePlane &input, double thresh)
{
SDoublePlane output(input.rows(), input.cols());
SDoublePlane outputx = sobel_gradient_filter(input,True);
SDoublePlane outputy = sobel_gradient_filter(input,false);

for(int i=0;i<outputx.rows();i++)
{
        for(int j=0;j<outputy.cols();j++)
        {
               output[i][j]=sqrt(pow(outputx[i][j],2)+pow(outputy[i][j],2)) ;


//if(i<outputx.rows()-1 && i>0 && j<outputy.cols()-1 && j>0 )
//{
//output[i+1][j+1]=sqrt(pow(outputx[i+1][j+1],2)+pow(outputy[i+1][j+1],2)) ;
//output[i-1][j-1]=sqrt(pow(outputx[i-1][j-1],2)+pow(outputy[i-1][j-1],2)) ;
//output[i][j-1]=sqrt(pow(outputx[i][j-1],2)+pow(outputy[i][j-1],2)) ;
//output[i-1][j]=sqrt(pow(outputx[i-1][j],2)+pow(outputy[i-1][j],2)) ;
//}

//cout<<output[i][j]<<endl;               
//change as implementation goes on
if (output[i][j]>=thresh)
 {

output[i][j]=0;

}


                                        else
                                        {
                                            output[i][j]=255;
                                            }
               
        }
}


for(int i=0;i<outputx.rows();i++)
{
        for(int j=0;j<outputy.cols();j++)
        {
if(i<outputx.rows()-1 && i>0 && j<outputy.cols()-1 && j>0 )
{
if((output[i][j]>output[i+1][j+1]) && (output[i][j]>=output[i-1][j-1]))
{

output[i][j]=0;
}

else
{
output[i][j]=255;
}

} 
}

}
        
  // Implement an edge detector of your choice,
  // use your sobel gradient operator to compute the gradient magnitude
  
  return output;
}