mobb[1] = 1;
for(int i=1;i<=m;i++){
	for(int j=i+i;j<=m;j+=i){
		mobb[j] -= mobb[i];
	}
}