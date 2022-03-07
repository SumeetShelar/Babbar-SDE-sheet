#include <iostream>
using namespace std;

int main() {
	int arr[] = {0,1,2,2,2,0,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	sort0123(arr,n);
	for(int i=0;i<n;i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}
