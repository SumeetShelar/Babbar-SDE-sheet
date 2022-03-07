//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

//Approach 1 -> counting number of 0,1,2 and then reconstructing the array
void sort012(int arr[], int n) {
	int num0 = 0, num1 = 0, num2 = 0;
	for(int i=0;i<n;i++) {
		if(arr[i] == 0) num0++;
		else if(arr[i] == 1) num1++;
		else num2++;
	}
	
	int i = 0;
	while(num0--) arr[i++] = 0;
	while(num1--) arr[i++] = 1;
	while(num2--) arr[i++] = 2;
}

//Approach 2 -> Dutch national flag problem
/*There are 4 regions -
[A] 1 to lo -> 0
[B] lo to mid -> 1
[C] mid to hi -> unknown
[D] hi to n -> 2
The idea is to shrink region [C] (mid to hi)*/
void sort012(int arr[], int n) {
	int lo = 0, hi = n-1, mid = 0;
	
	while(mid<=hi) {
		switch(arr[mid]) {
			case 0:
				swap(arr[lo++],arr[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(arr[hi--],arr[mid]);
				break;
		}
	}
}
