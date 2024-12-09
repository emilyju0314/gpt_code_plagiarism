bool areIsomorphic(string s1, string s2)
{
    
    if(s1.length()!=s2.length())
        return 0;
        
    bool present[256]={false};
    int map[256];
    memset(map,-1,sizeof(map));
    
    for(int i=0;i<s1.length();++i)
      {
          if(map[s1[i]]==-1) //first occurence
          {
              if(present[s2[i]])
                  return false;
                  
              present[s2[i]]=true;
              map[s1[i]]=s2[i];
          }
          
          else
          {
              if(map[s1[i]]!=s2[i])
                 return false;
          }
      }
      
      return true;
}