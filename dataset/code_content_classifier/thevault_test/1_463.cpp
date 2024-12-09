int tab::neigh(int x,int y){
	int cnt=0;
	FOR2(i,-1,2){
		FOR2(j,-1,2){
			if(!i && !j)continue;
			int xx=(x+i)%lar, yy=(y+j)%alt;
			if(xx<0)xx+=lar;
			if(yy<0)yy+=alt;
			if(v[xx][yy])cnt++;
		}
	}
	return cnt;
}