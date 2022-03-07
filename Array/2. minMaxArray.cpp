//Find minimum and maximum element in an array

pair<long long, long long> getMinMax(long long a[], int n) {
    long long min,max;
    
    if(n==1) {
    	return {a[0],a[0]};
	}
	
	if(a[0] > a[1]) {
		min = a[1];
		max = a[0];
	} else {
		min = a[0];
		max = a[1];
	}
    
    for(int i=2;i<n;i++) {
        if(min > a[i]) min = a[i];
        else if(max < a[i]) max = a[i];
    }
    
    return {min,max};
}
