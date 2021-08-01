#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* next;
};

int length ( Node *head ) 
{
    int i = 0;
    Node * p = head;
    while ( p != NULL ) {
        i++;
        p = p->next;
    }
    return i;
}
void print(Node* head)
{
    while(head != NULL)
    {
        cout << head->value << ' ';
        head = head->next;
    }
}

void printReverse( Node* head )
{
    vector<int> a;
    Node *p = head;
    while ( p != NULL ) {
        a.push_back ( p->value );
        p = p ->next;
    }
    for (int i= a.size()-1; i>=0; i-- )
        cout << a[i] << " ";

}

void printLast(Node* head )
{
    Node *p = head;
    while ( p->next != NULL ) {
        p = p->next;
    }
    cout << p->value << endl;
}

void rotate(Node* head, int k)
{
    int count_ = 0, n = 0;
    Node* tail = head;

    if(head == NULL) return;

    while (tail->next != NULL)
    {
        tail = tail->next;
        n++;
    }

    if(k >= n) return;
    
    while(count_ != k)
    {
        count_++;
        Node* p = head;

        head = head->next;
        p->next = NULL;

        tail->next = p;
        tail = p;

    }

    print(head);
    exit(0);
} 

Node* deleteNode(Node* head, int pos) // xoa Node o vi tri bat ki
{
    if(pos == 0) {
        head = head->next;
        return head;
    }
    int i = 0;
    Node* p = head;
    while( p != NULL)
    {
        i++;
        if(i == pos)
        {
            p->next = p->next->next;
            return head;
        }
        p = p->next;
    }
    return head;
}

Node* insertTail(Node* head, int value) // chen cuoi
{
    Node* p = head;
    
    Node* newNode = new Node();
    newNode->next = NULL;
    newNode->value = value;
    
    if(head == NULL) {
        head = newNode;
        return head;
    }
    
    while( p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return head;
}

Node* deleteSingle( Node* head )
{
    Node* p = head;
    
    if( p->value != p->next->value) {
        return ( p->next );
    }
    
    for(p = head; p != NULL; p = p->next) {
        if( p->next->next == NULL ) {
            p->next = NULL;
            return head;
        }
        if(p->value != p->next->value && p->next->value != p->next->next->value ) {
            p->next = p->next->next;
            return head;
        }
    }
    return head;
}

Node* deleteDuplicates(Node* head) // xoa trung lap
{
    
    if(head == NULL) return head;
    Node *p = head;
    while ( p-> next != NULL ) {
        if ( p->value == p->next->value ) {
            p->next = p->next->next;
        }
        else {
            p = p ->next;
        }
    }
    return head;
}

Node* insertHead(Node* head, int value) //chen dau
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    if ( head == NULL ) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;

}

Node* convert(Node* head)
{
    Node* p = head;
    Node* q = head;
    int n = 0, i = 0;

    while(p != NULL)
    {
        n++;
        p = p->next;
    }

    p = head;

    bool ok_ = true;

    while (p != NULL && q != NULL)
    {
        i++;
        if(i <= n/2)
        {
            q = q->next;
            continue;
        } 

        Node* replace_ = head;
        int i = 0;

        while(ok_)
        {
            i++;    
            if(i == n/2)
            {
                ok_ = false;
                replace_->next = NULL;
                break;
            }
            replace_ = replace_->next;
        }
        
        Node* q_ = q;
        Node* p_ = p;
        q = q->next;
        p = p->next;

        q_->next = p_->next;
        p_->next = q_;
        cout <<"";

    }
    
    return head;
}

Node* insert (Node* head, int value) // chen day tang
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = NULL;
    //insert head;
    if ( head == NULL || head->value >= value ) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    //insert taill
    Node *p = head;
    while ( p->next != NULL && p->next->value < value ) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

Node* vectorToLinkedList(vector<int> values) // chuyen vector sang llist
{
    Node *res = new Node;
    res->value = values[0];
    res->next = NULL;

    Node *p = res;
    for ( int i= 1; i< values.size(); i++ ) {
        Node *newNode = new Node;
        newNode->value = values[i];
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
    }
    p->next = NULL;
    return res;
}

Node* concat ( vector<Node*> heads )  // noi linklist
{
    int size = heads.size();
    int pos = 0;
    for ( int i= 0; i< size; i++ ) {
        if ( heads[i] == NULL ) {
            pos = i;
            break;
        }
    }
    Node *res = heads[pos];
    Node *p = res;
    while ( p->next != NULL ) {
        p = p->next;
    }
    for ( int i = pos +1; i< size; i++ ) {
        if ( heads[i] == NULL ) continue;
        p->next = heads[i];
        while ( p->next != NULL ) {
            p = p->next;
        }
    }
    p->next = NULL;
    return res;
}

Node* reverseLinkedList ( Node *head ) // dao nguoc linked list
{
    if ( head == NULL ) return head;
    Node *prev = head;
    Node *current = head->next;
    head->next = NULL;
    
    while ( current != NULL ) {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *mergeLists ( Node *head1, Node *head2 ) // gop 2 linked list tang dan
{
    if ( head1 == NULL ) return head2;
    if ( head2 == NULL ) return head1;

    Node *res = NULL;
    if ( head1->value < head2->value ) {
        res = head1;
        head1 = head1->next;
    }
    else {
        res = head2;
        head2 = head2->next;
    }

    Node *p = res;
    while ( head1 != NULL && head2 != NULL ) {
        if ( head1->value < head2->value ) {
            p->next = head1;
            head1 = head1->next;
        }
        else {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    if ( head1 == NULL ) {
        p->next = head2;
    }
    else {
        p->next = head1;
    }
    return res;
    
}

int findMergeNode ( Node *head1, Node *head2 ) // tim gia tri trung nhau cua 2 llist
{
    Node *p1 = head1;
    Node *p2 = head2;
    while ( p1 != p2 ) {
        p1 = p1->next;
        p2 = p2->next;
        if ( p1 == NULL ) p1 = head1;
        if ( p2 == NULL ) p2 = head2;
    }
    return p1->value;
}

bool has_cycle( Node* head ) //kiem tra vong lap
{
    if ( head == NULL ) return false;
    Node *fast = head;
    Node *slow = head;
    while ( slow != NULL && fast->next != NULL ) {
        fast = fast->next->next;
        slow = slow ->next;
        if ( fast == slow ) return true;
    }
    return false;
}


int main()
{
    
    int n, x;

    cin >> n;
    cin >> x;

    Node* head = new Node();
    head->value = x;
    head->next = NULL;

    for(int i = 2; i <= n; i++)
    {
        int X;
        cin >> X;
        Node* temp = insertTail(head,X);
    }
    
    //Node *res = insert ( head, 8 );
    //cout << length ( head )  << endl;
    //print(res);
    printReverse ( head );
    //printLast ( head );
    return 0;
}