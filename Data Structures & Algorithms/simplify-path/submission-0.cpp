class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int index = 1;

        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                string str = path.substr(index, i - index);

                if (str == "..") {
                    if (!st.empty()) st.pop();
                } else if (str == "." || str.empty()) {
                } else {
                    st.push(str);
                }

                index = i + 1;
            }
        }

        string str = path.substr(index);

        if (str == "..") {
            if (!st.empty()) st.pop();
        } else if (str != "." && !str.empty()) {
            st.push(str);
        }

        string result = "";

        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};