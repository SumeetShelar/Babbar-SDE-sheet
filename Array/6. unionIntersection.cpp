//Find the Union and Intersection of the two sorted arrays.

//Union of two sorted arrays
vector<int> unionSorted(int a[], int n, int b[], int m) {
	int i=0, j=0;
	vector<int> ans;
	while(i<n && j<m) {
		if(a[i] < b[j]) {
			ans.push_back(a[i++]);		//incrementing 'i' pointer in 'a'
		} else if(a[i] > b[j]) {
			ans.push_back(b[j++]);		//incrementing 'j' pointer in 'b'
		} else {
			ans.push_back(a[i]);		//incrementing both pointers
			i++;
			j++;
		}
	}
	while(i<n) ans.push_back(a[i++]);	//adding remaining elements from 'a'
	while(j<m) ans.push_back(b[j++]);	//adding remaining elements from 'b'
	
	return ans;
}

//Intersection of two sorted arrays
vector<int> intersectionSorted(int a[], int n, int b[], int m) {
	int i=0, j=0;
	vector<int> ans;
	while(i<n && j<m) {
		if(a[i] == b[j]) {
			ans.push_back(a[i]);	//if same only then adding in 'ans'
			i++;					//incrementing both pointers
			j++;
		} else if(a[i] < b[j]) {	//incrementing 'i' pointer in 'a'
			i++;
		} else {					//incrementing 'j' pointer in 'b'
			j++;
		}
	}
	return ans;
}

//Union of two Unsorted arrays
//Using set DS as no duplicates are allowed so it will always be the UNION of both arrays
vector<int> unionUnsorted(int a[], int n, int b[], int m) {
	set<int> s;
	vector<int> ans;
	
	for(int i=0;i<n;i++) s.insert(a[i]);	//adding all elements from 'a'
	
	for(int i=0;i<m;i++) s.insert(b[i]);	//adding all elements from 'b'
	
	for(auto &it:s) ans.push_back(it);		//copying to 'ans' from 's'
	
	return ans;
}	

//Intersection of two Unsorted arrays
//Using map DS to identify the duplicates i.e. INTERSECTION of both arrays
vector<int> intersectionUnsorted(int a[], int n, int b[], int m) {
	mi<int, int> mp;
	vector<int> ans;
	
	for(int i=0;i<n;i++) mp[a[i]]++;	//adding all elements from 'a' with a value '1'
	
	for(int i=0;i<m;i++) mp[b[i]]++;	//adding all elements from 'b' with value '1' for newones and 'val+1' for duplicates
	
	for(auto &elem:mp) {				//copying duplicates i.e. elements with 'val > 1' to 'ans' from 'mp'
		if(elem.second > 1) {
			ans.push_back(elem.first);	
		}
	}
	return ans;
}
