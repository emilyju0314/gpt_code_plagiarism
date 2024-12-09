double Vec3D::at(int n)
{

double Value=0;


    if(n==0)
    {
        Value=m_X;
    }
    else if(n==1)
    {
        Value=m_Y;
    }
    else if(n==2)
    {
        Value=m_Z;
    }
    else
    {
        std::cout<<"Error: index should not be larger the 2 \n";
    }
    
    


return Value; 
}