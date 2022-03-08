//Move all the negative elements to one side of the array 

//#1 - Don't care about the order of elements
void moveNegatives(int arr[], int n) {
	int start = 0, end = n-1;
	while(start < end) {
		while(arr[start] < 0) start++;
		while(arr[end] > 0) end--;
		if(start < end) swap(arr[start++], arr[end--]);
	}
}

//#2 - We care about the order of elements
//Approach 1 - using a different array and adding -ve's and +ve's to it
void moveNegatives(int arr[], int n) {
	int temp[n];	//temp array
	int k = 0,i;
	//Copying -ve's
	for(i=0;i<n;i++) {
		if(arr[i] < 0) temp[k++] = arr[i];
	}
	//Copying +ve's
	for(i=0;i<n;i++) {
		if(arr[i] >= 0) temp[k++] = arr[i];
	}
	//Copying from temp to arr
	for(i=0;i<n;i++) {
		arr[i] = temp[i];
	}
}

//Approach 2 - Merge sort like approach 
//	-> Dividing array into subarrays and arranging the -ve and +ve part of each part and then merging them

//Reverse the array
void reverse(int arr[], int l, int r) {
	if(l<r) {
		int temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
		reverse(arr,++l,--r);
	}
}

//Merges two subarrays of arr[]. 
//First subarray is arr[l..m] 
//Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
	int i = l;		//Initial index of 1st subarray 
    int j = m + 1; //Initial index of 2nd
	
	while(i<=m && arr[i] < 0) i++;		// arr[i..m] is positive
	while(j<=r && arr[j] < 0) j++;		// arr[j..r] is positive
	
	//reverse positive part of left sub-array (arr[i..m])
	reverse(arr,i,m);
	
	//reverse negative part of right sub-array (arr[m+1..j-1]) 
	reverse(arr,m+1,j-1);
	
	//reverse arr[i..j-1]
	reverse(arr,i,j-1);
}

void moveNegativesHelper(int arr[], int l, int r) {
	if(l<r) {
		int mid = (l+r)/2;
		
		//Sort first and second halves
		moveNegativesHelper(arr,l,mid);
		moveNegativesHelper(arr,mid+1,r);
		
		merge(arr,l,mid,r);
	}
}

void moveNegatives(int arr[], int n) {
	moveNegativesHelper(arr,0,n-1);		//helper func
}
