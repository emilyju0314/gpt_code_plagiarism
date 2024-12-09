        #include<cstdio>
        char a[50][51],b[50][51];
        int main()
        {
        int i,j,k,l,n,m;scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)scanf("%s",a[i]);
        for(i=0;i<m;i++)scanf("%s",b[i]);
        for(i=0;i<=n-m;i++)
        for(j=0;j<=n-m;j++){
        bool f=true;
        for(k=0;k<m&&f;k++)
        for(l=0;l<m&&f;l++)
        if(a[i+k][j+l]!=b[k][l])f=false;
        if(f)return puts("Yes"),0;
        }
        puts("No");
        return 0;
        }