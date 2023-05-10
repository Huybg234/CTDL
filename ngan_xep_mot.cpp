#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st; 
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push") {
            int x;
            cin >> x;
            st.push(x); 
        } else if (cmd == "pop") {
            if (!st.empty()) {
                st.pop(); 
            }
        } else if (cmd == "show") {
            if (st.empty()) {
                cout << "empty" << endl; 
            } else {
                stack<int> temp; 
                while (!st.empty()) {
                    temp.push(st.top()); 
                    st.pop(); 
                }
                while (!temp.empty()) {
                    cout << temp.top() << " "; 
                    st.push(temp.top()); 
                    temp.pop();
                }
                cout << endl;
            }
        }
    }
    return 0;
}

