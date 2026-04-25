class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for (string op : operations) {
            if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                int sum = top1 + top2;
                st.push(top1);   // push back
                st.push(sum);
            }
            else if (op == "D") {
                st.push(2 * st.top());
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};