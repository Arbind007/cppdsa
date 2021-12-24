#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void printinorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printinorder(root->left);
    cout << root->data << ' ';
    printinorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

Node *buildTree2(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->right = buildTree2(postorder, inorder, pos + 1, end);
    node->left = buildTree2(postorder, inorder, start, pos - 1);

    return node;
}

void printlevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAtK(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty() && level <= k)
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}

int sumNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumNode(root->left) + sumNode(root->right) + root->data;
}

int calheight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = calheight(root->left);
    int rheight = calheight(root->right);
    return max(lheight, rheight) + 1;
}

int calcDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = calheight(root->left);
    int rheight = calheight(root->right);
    int curr = rheight + lheight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(curr, max(lDiameter, rDiameter));
}

int calcDiameter2(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calcDiameter2(root->left, &lh);
    int rDiameter = calcDiameter2(root->right, &rh);

    int currD = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currD, max(lDiameter, rDiameter));
}

void sumreplace(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    sumreplace(root->left);
    sumreplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

bool isbalance(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isbalance(root->left) == false)
    {
        return false;
    }
    if (isbalance(root->right) == false)
    {
        return false;
    }

    int lh = calheight(root->left);
    int rh = calheight(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isbalance2(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (isbalance2(root->left, &lh) == false)
    {
        return false;
    }
    if (isbalance2(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << endl;
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << endl;
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    { // both left and right have either n1 or n2
        return root;
    }

    if (right == NULL && left == NULL)
    { //not found
        return NULL;
    }
    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDis(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        return dist;
    }

    int left = findDis(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findDis(root->right, k, dist + 1);
}

int disBtwNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDis(lca, n1, 0);
    int d2 = findDis(lca, n2, 0);

    return d1 + d2;
}

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {
        flatten(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node *t1 = root->right;

        while (t1->right != NULL)
        {
            t1 = t1->right;
        }
        t1->right = temp;
    }
    flatten(root->right);
}

void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << ' ';
    }
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

int printNodeatK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }
    int dl = printNodeatK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << ' ';
        }
        else
        {
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodeatK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << ' ';
        }
        else
        {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

bool getPath(Node *root, int key, vector<int> &path)
{

    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();

    return false;
}

int LCA2(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path1[pc - 1];
}

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + right + left), max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(3);
    root->right->right = new Node(5);
    // root->right->left = new Node(5);
    // root->right->left->left = new Node(7);
    // preorder(root);
    // inorder(root);
    // postorder(root);

    // sumreplace(root);
    // cout << endl;
    // preorder(root);

    // int preorder[] = {1, 2, 4, 3, 5};
    // int postorder[] = {4, 2, 5, 3, 1};
    // int inorder[] = {4, 2, 1, 5, 3};

    // Node *root = buildTree2(postorder, inorder, 0, 4);
    // printinorder(root);

    // printlevelOrder(root);
    // cout << sumAtK(root, 1) << endl;
    // cout << countNode(root) << endl;
    // cout << calcDiameter(root) << endl;
    // int height = 0;
    // cout << calcDiameter2(root, &height) << endl;

    // cout << isbalance(root) << endl;
    // int height = 0;
    // cout << isbalance2(root, &height) << endl;

    // leftView(root);

    // cout << disBtwNodes(root, 4, 5) << endl;

    // flatten(root);
    // printinorder(root);

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // printNodeatK(root, root->left, 1);

    // int n1 = 7;
    // int n2 = 6;
    // Node *lca = LCA(root, n1, n2);

    // if (lca == NULL)
    // {
    //     cout << "LCA does not exist" << endl;
    // }
    // else
    // {
    //     cout << "LCA : " << lca->data << endl;
    // }

    cout << maxPathSum(root) << endl;
    return 0;
}