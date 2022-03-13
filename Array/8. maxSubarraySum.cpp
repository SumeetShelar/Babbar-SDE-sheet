//find Largest sum contiguous Subarray [V. IMP]

long long maxSubarraySum(int arr[], int n) {
	long long max_so_far = INT_MIN, max_ending_here = 0;
	
	for(int i=0;i<n;i++) {
		//Updating max sum till current index
		max_ending_here += arr[i];
		
		//Storing max sum so far by choosing maximum between max sum so far and max till current index
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
			
		//If max sum at current index is negative, we do not need to add it to result so we update it to zero
		if(max_ending_here < 0)
			max_ending_here = 0;
	}
	
	return max_so_far;
}
