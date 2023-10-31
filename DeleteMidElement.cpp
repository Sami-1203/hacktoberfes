#include <iostream>  // deleting mid stack element using recursion 
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &s, int sizeOfStack) {
    stack<int> tempStack;
    int mid = sizeOfStack/2; // Find the index of the middle element

    // Pop and push elements to a temporary stack until we reach the middle element
    for (int i = 0; i < mid; ++i) {
        tempStack.push(s.top());
        s.pop();
    }

    // Skip the middle element by popping it from the original stack
    s.pop();

    // Push the elements back from the temporary stack to the original stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    int n;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.push(x);
    }

    deleteMiddle(st, n);

    // Printing the modified stack after removing the middle element
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
