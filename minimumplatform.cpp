/*
Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits. 
We are given two arrays that represent the arrival and departure times of trains that stop.

Input Format

size of the array first array is arrival time elements second array is departure times elements

Constraints

Constraints: 1 ≤ n ≤ 50000
0000 ≤ A[i] ≤ D[i] ≤ 2359

Expected Time Complexity: O(nLogn) Expected Auxiliary Space: O(1)

Output Format

print the minimum platforms

Sample Input 0

6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
Sample Output 0

3
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int> arrival(n);
    vector<int> departure(n);
    for(int i=0;i<n;i++) cin>>arrival[i];
    for(int j=0;j<n;j++) cin>>departure[j];
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int i=0,j=0;
    int count=0;
    int maxi=0;
    while(i<n && j<n)
    {
        if(departure[j]>arrival[i])
        {
            count++;
            maxi=max(maxi,count);
            i++;
        }
        else
        {
            count--;
            j++;
        }
        
    }
    cout<<maxi;
    return 0;
}
