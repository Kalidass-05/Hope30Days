/*
Problem in Simple Words

You are given intervals (each balloon lies between start and end).

One arrow shot at position x can burst all balloons where start ≤ x ≤ end.

Find the minimum arrows needed.

Approach (Greedy)

1. Sort intervals by their end coordinate.
Why? → If you always shoot the arrow at the earliest ending balloon, you maximize the chance of hitting more balloons with that one arrow.

2. Shoot first arrow at the end of the first balloon.
    Keep a variable arrpos = points[0][1] (arrow position).
    Start with arrow = 1.

3. Traverse through balloons:
      If the current balloon’s start > arrpos, that balloon can’t be burst by the current arrow.
      Shoot a new arrow (arrow++) at points[i][1].
      Else, if start ≤ arrpos, it means the current balloon overlaps with previous ones → already burst by the same arrow.

4. Return arrow at the end.
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    if(points.empty()) return 0;

    sort(points.begin(),points.end(),[](vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    });

    int arrpos=points[0][1];
    int arrow=1;
    for(int i=0;i<points.size();i++)
    {
        if(points[i][0]>arrpos)
        {
            arrow++;
            arrpos=points[i][1];
        }
    }
    return arrow;
    }
};
