#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool isLeaf(TreeNode *r) {
        return r && !r->left && !r->right;
    }
    void DFS(TreeNode *r, int &sum) {
        if (!r) return;
        if (r->left) {
            if (isLeaf(r->left)) sum += r->left->val;
            DFS(r->left, sum);
        }
        DFS(r->right, sum);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        int sum = 0;
        DFS(root, sum);
        return sum;
    }
};

void test1() {
    vector<int> v1{3, 9, 20, -1, -1, 15, 7};
    TreeNode *t1 = new TreeNode(v1, -1);
    cout << "24 ? " << Solution().sumOfLeftLeaves(t1) << endl;


    vector<int> v2{1,2,3,4,5};
    TreeNode *t2 = new TreeNode(v2);
    cout << t2 << endl;
    cout << "4 ? " << Solution().sumOfLeftLeaves(t2) << endl;
//    cout << " ? " << Solution().func() << endl;
}

void test2() {

}

void test3() {

}