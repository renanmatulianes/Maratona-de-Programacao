#include <iostream>
#include <string>

using namespace std;

void printPostOrder(string pre, string in) {
    if (pre.empty() || in.empty()) {
        return;
    }

    char root = pre[0];
    int rootIdx = in.find(root);

    string leftIn = in.substr(0, rootIdx);
    string rightIn = in.substr(rootIdx + 1);

    string leftPre = pre.substr(1, leftIn.length());
    string rightPre = pre.substr(1 + leftIn.length());

    printPostOrder(leftPre, leftIn);
    printPostOrder(rightPre, rightIn);

    cout << root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pre, in;

    while (cin >> pre >> in) {
        printPostOrder(pre, in);
        cout << "\n";
    }

    return 0;
}