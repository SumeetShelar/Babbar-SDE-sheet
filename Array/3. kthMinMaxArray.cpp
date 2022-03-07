//Find the "Kth" max and min element of an array 

pair<int,int> kthMaxMinElement(int arr[], int l, int r, int k) {
//Approach 1 -> Using merge sort
//	mergeSort(arr,l,r);
//	return {arr[k-1],arr[r-k+1]};

//Approach 2 -> Using set
	set<int> s(arr,arr+r+1);
	
	set<int>::iterator minItr = s.begin();
	set<int>::reverse_iterator maxItr = s.rbegin();	//reverse iterator to find max
	
	//advance used to point the iterator to given position
	advance(minItr,k-1);
	advance(maxItr,k-1);
	
	return {*minItr,*maxItr};	//returning a pair of min and max
}
