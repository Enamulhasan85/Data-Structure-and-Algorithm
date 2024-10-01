f[i] = number of tuples with GCD as multiple of i
g[i] = number of tuples with GCD as i
for(int i = maxn; i >= 1; i--){
	g[i] = f[i];
	for(int j=2*i;j <= maxn; j+=i){
		g[i] -= g[j];
	}
}