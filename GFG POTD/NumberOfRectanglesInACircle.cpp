/*
    Hints : 
    1. for a given length, what's the max width rectangle that we can fit in the circle;
*/

/*
    Solution : 
    Find the rectangle with the largest (real no.) width for each lenght [1, 2 * r] (why ?) (triangle in a semicircle makes 90 deg)
    Then you can easily find all the rectangles with length (say l)

    T.C. O (2 * r)
    S.C. O (1)
*/

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int res;
        for (int l = 1; l <= 2 * r; l += 1) {
            int mx_w = floor (sqrt ((4 * r * r) - (l * l)));
            res += mx_w;
        }
        return res;
    }
};