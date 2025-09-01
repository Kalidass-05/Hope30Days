/*Q. an array of size N. Which has the following specifications: Each element in the array contains either a policeman or a thief. Each policeman can catch only one thief. 
A policeman cannot catch a thief who is more than K units away from him. We need to find the maximum number of thieves that can be caught.*/
/*
Test Case: 
Sample Input 0

6
P
T
P
T
T
P
3
Sample Output 0

Maximum thieves caught: 3
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    vector<int> p;
    vector<int> t;
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='P')
        {
            p.push_back(i);
        }
        else
        {
            t.push_back(i);
        }
    }
    size_t i=0,j=0;
    int count=0;
    while(i<p.size() && j<t.size())
    {
        int dif = abs(p[i]-t[j]);
        if(dif<=k)
        {
            count++;
            i++;
            j++;
        }else if(p[i]<t[j]){
            i++;
        }
        else {
            j++;
        }
    }
    cout<<"Maximum thieves caught: "<<count;
    return 0;
}
