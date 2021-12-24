#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

bool linearSearch(node *&head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteHead(node *&head)
{
    node *temp = head;
    head->next = head;
    delete temp;
}

void deleteNode(node *&head, int val)
{

    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node *reverse(node *&head)
{
    node *prevN = NULL;
    node *presentN = head;
    node *nextN;

    while (presentN != NULL)
    {
        nextN = presentN->next;
        presentN->next = prevN;
        prevN = presentN;
        presentN = nextN;
    }

    return prevN;
}

node *reverse2(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *reversek(node *&head, int k)
{
    node *prevN = NULL;
    node *presentN = head;
    node *nextN;

    int count = 0;
    while (presentN != NULL && count < k)
    {
        nextN = presentN->next;
        presentN->next = prevN;
        prevN = presentN;
        presentN = nextN;
        count++;
    }

    if (nextN != NULL)
    {
        head->next = reversek(nextN, k);
    }
    return prevN;
}

void makeCycle(node *&head, int val)
{
    node *temp = head;
    node *startnode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == val)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

void deleteCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int length(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

node *appendknode(node *&head, int len)
{
    node *newhead;
    node *newTail;
    node *tail = head;
    int leng = length(head);
    len = len % leng;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == leng - len)
        {
            newTail = tail;
        }
        if (count == leng - len + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newhead;
}

int findintersection(node *&head, node *&newhead)
{
    int counto = length(head);
    int countt = length(newhead);
    node *tempp = head;
    node *temp = newhead;

    if (counto < countt)
    {
        int diff = countt - counto;
        int count = 0;

        while (count < diff)
        {
            temp = temp->next;
            count++;
        }
    }

    else if (counto > countt)
    {
        int diff = counto - countt;
        int count = 0;

        while (count < diff)
        {
            tempp = tempp->next;
            count++;
        }
    }

    while (temp != NULL && tempp != NULL)
    {
        if (temp == tempp)
        {
            return temp->data;
        }
        temp = temp->next;
        tempp = tempp->next;
    }
    return -1;
}

void intersection(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    node *temp2 = head2;

    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

node *mergerll(node *&head1, node *&head2)
{
    node *fnode = new node(-1);
    node *p1 = head1;
    node *p2 = head2;
    node *f = fnode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            f->next = p1;
            p1 = p1->next;
        }
        else
        {
            f->next = p2;
            p2 = p2->next;
        }
        f = f->next;
    }

    while (p1 != NULL)
    {
        f->next = p1;
        p1 = p1->next;
        f = f->next;
    }
    while (p2 != NULL)
    {
        f->next = p2;
        p2 = p2->next;
        f = f->next;
    }
    return fnode->next;
}

node *recursivemerge(node *&head1, node *&head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = recursivemerge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = recursivemerge(head1, head2->next);
    }
    return result;
}

void oddeven(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}

// node *addsum(node *l1, node *l2)
// {
//     node *newhead = new node(-1);
//     node *temp1 = l1;
//     node *temp2 = l2;
//     node *nwp = newhead;
//     long long sum1 = 0, sum2 = 0;
//     long long pos = 1;
//     while (temp1 != NULL)
//     {
//         sum1 += (temp1->data) * pos;
//         temp1 = temp1->next;
//         pos *= 10;
//     }
//     pos = 1;
//     while (temp2 != NULL)
//     {
//         sum2 += (temp2->data) * pos;
//         temp2 = temp2->next;
//         pos *= 10;
//     }
//     sum1 += sum2;
//     while (sum1 != 0)
//     {
//         int val = sum1 % 10;
//         nwp->next = new node(val);
//         nwp = nwp->next;
//         sum1 /= 10;
//     }
//     return newhead->next;
// }

void printLinkedList(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    node *head2 = NULL;

    insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 3);

    insertAtTail(head2, 3);
    // insertAtTail(head2, 6);
    // insertAtTail(head2, 4);
    // insertAtHead(head, 1);
    // deleteNode(head, 2);
    printLinkedList(head2);
    // cout << linearSearch(head, 4) << endl;
    // node *newhead = reverse(head);
    // printLinkedList(newhead);
    // int k = 2;
    // node *newhead = addsum(head, head2);
    // printLinkedList(newhead);
    // makeCycle(head, 3);
    // cout << detectCycle(head) << endl;
    // deleteCycle(head);
    // cout << detectCycle(head) << endl;
    // printLinkedList(head);
    // node *newhead = appendknode(head, 3);
    // printLinkedList(newhead);
    // insertAtTail(head2, 9);

    // intersection(head, head2, 4);
    // printLinkedList(head);
    // printLinkedList(head2);
    // cout << findintersection(head, head2) << endl;
    // insertAtTail(head2, 2);
    // insertAtTail(head2, 4);
    // insertAtTail(head2, 6);
    // insertAtTail(head2, 8);
    // insertAtTail(head2, 10);
    // printLinkedList(head2);
    // node *newhead = recursivemerge(head, head2);
    // printLinkedList(newhead);
    // oddeven(head);
    // printLinkedList(head);
    return 0;
}