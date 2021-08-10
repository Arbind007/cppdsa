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

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
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

    cout << isbalance(root) << endl;
    int height = 0;
    cout << isbalance2(root, &height) << endl;
    return 0;
}