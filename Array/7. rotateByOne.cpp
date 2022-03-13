//Write a program to cyclically rotate an array by one

void rotate(int arr[], int n) {
	int last = arr[n-1];	//storing last element
	for(int i=n-1;i>0;i--) {	//shifting elements to right by 1
		arr[i] = arr[i-1];
	}
	arr[0] = last;		//updating the 1st element
}
