//Minimise the maximum difference between heights [V.IMP]

int getMinDiff(int arr[], int n, int k) {
	sort(arr,arr+n);
	int ans = arr[n-1] - arr[0];
	int smallest = arr[0]+k;
	int largest = arr[n-1] - k;
	
	for(int i=0;i<n-1;i++) {
		int minH = min(smallest, arr[i+1]-k);
		int maxH = max(largest, arr[i]+k);
		if(min < 0) continue;
		ans = min(ans, largest-smallest);
	}
	return ans;
}
