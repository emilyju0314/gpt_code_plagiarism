void RouteLogic::hier_print_route()
{
	for (int j=1; j < D_; j++) 
		for (int k=1; k < C_[j]; k++) {
			int i = INDEX(j, k, Cmax_);
			int s = (cluster_size_[i]+C_[j]+D_);
			printf("ROUTE_TABLE[%d] for cluster %d.%d :\n",i,j,k);
			int temp = 1;
			printf(" ");
			while(temp < s){
				printf(" %d",temp);
				temp++;
			}
			printf("\n");
			for(int n=1; n < s; n++){
				printf("%d ",n);
				for(int m=1; m < s; m++)
					printf("%d ",hroute_[i][INDEX(n, m, s)]);
				printf("\n");
			}
			printf("\n\n");
		}
}