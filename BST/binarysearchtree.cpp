#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void printpreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

Node *searchInBst(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchInBst(root->left, key);
    }
    return searchInBst(root->right, key);
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }

    return root;
}

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        if (*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid && rightValid;
}

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

vector<Node *> constructTree(int start, int end)
{
    vector<Node *> trees;

    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSub = constructTree(start, i - 1);
        vector<Node *> rightSub = constructTree(i + 1, end);
        for (int j = 0; j < leftSub.size(); j++)
        {
            Node *left = leftSub[j];
            for (int k = 0; k < rightSub.size(); k++)
            {
                Node *right = rightSub[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool cond1 = (root1->data == root2->data);
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
    }
}

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    int isBST;
};

Info largestBSTinBT(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(leftInfo.max, max(rightInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calcPointers(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

int main()
{
    // struct Node *root = NULL;
    // root = insertBST(root, 5);
    // insertBST(root, 1);
    // insertBST(root, 3);
    // insertBST(root, 4);
    // insertBST(root, 2);
    // insertBST(root, 7);
    // inorder(root);
    // if (searchInBst(root, 5) != NULL)
    // {
    //     cout << "Key Exists" << endl;
    // }
    // else
    // {
    //     cout << "Doesn't Exists" << endl;
    // }
    // inorder(root);
    // root = deleteInBST(root, 5);
    // inorder(root);

    // int preorder[] = {10, 2, 1, 13, 11};
    // int n = 5;
    // int preorderIdx = 0;
    // Node *root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    // printpreorder(root);

    // Node *root = new Node(2);
    // root->left = new Node(1);
    // root->right = new Node(3);
    // cout << isBST(root, NULL, NULL) << endl;

    // int arr[] = {10, 20, 30, 40, 50};
    // Node *root = sortedArrayToBST(arr, 0, 4);
    // printpreorder(root);

    // vector<Node *> totalTree = constructTree(1, 3);

    // for (int i = 0; i < totalTree.size(); i++)
    // {
    //     cout << (i + 1) << " : ";
    //     printpreorder(totalTree[i]);
    //     cout << endl;
    // }

    // Node *root = new Node(12);
    // root->left = new Node(9);
    // root->right = new Node(15);
    // root->left->left = new Node(5);
    // root->left->right = new Node(10);
    // zigzagTraversal(root);

    // Node *root = new Node(2);
    // root->left = new Node(1);
    // root->right = new Node(3);

    // Node *root1 = new Node(2);
    // root1->left = new Node(1);
    // root1->right = new Node(5);

    // cout << isIdentical(root, root1) << endl;

    // Node *root = new Node(15);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->left = new Node(5);

    // cout << largestBSTinBT(root).ans << endl;

    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);
    restoreBST(root);
    inorder(root);

    return 0;
}