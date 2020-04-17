class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int max = 0;
    int start;
    int area;

    int i = 0;
    while (i < heights.size()) {
        if (s.size() == 0 || heights[s.top()] <= heights[i]) {
            s.push(i++);
        }
        else {
            start = s.top();
            s.pop();
            int width;
            if (s.size() == 0) {
                width = i;
            }
            else {
                width = i - s.top() - 1;
            }
            area = heights[start] * width;
            if (area > max) {
              max = area;
            }
        }
    }

    while (s.size() != 0) {
        start = s.top();
        s.pop();
        int width;
        if (s.size() == 0) {
            width = i;
        }
        else {
            width = i - s.top() - 1;
        }
        area = heights[start] * width;
        if (area > max) {
            max = area;
        }
    }

    return max;
    }
};
