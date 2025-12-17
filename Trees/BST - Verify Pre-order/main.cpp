// A pre-order traversal is valid when you recreate the tree after 
// inserting the elements from left to right, it will still have the same 
// pre-order traversal as the input. The challenge of this problem is 
// you are not to implement the tree.

// The idea is this: have the first element be the root, and what 
// follows after should be its left subtree and then its right subtree. 
// The first part (left subtree) should be smaller than the root and the second part 
// (right subtree) be larger than the root. If the second part contains an 
// element that is smaller than the root, the traversal is not valid.

// Note that this is recursive as you have to check for the same thing in the subtrees.

#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

bool isValidPreorder(const vector<int>& preorder) {
    stack<int> st;
    int lowerBound = numeric_limits<int>::min();

    for (int value : preorder) {
        // If we find a value smaller than allowed, it's invalid
        if (value < lowerBound)
            return false;

        // Pop from stack while value is greater than the top of stack
        // (meaning we are moving to the right subtree)
        while (!st.empty() && value > st.top()) {
            lowerBound = st.top();
            st.pop();
        }

        // Push current value as new root candidate
        st.push(value);
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> preorder(n);
    cout << "Enter preorder: ";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    if (isValidPreorder(preorder))
        cout << "VALID" << endl;
    else
        cout << "INVALID" << endl;

    return 0;
}