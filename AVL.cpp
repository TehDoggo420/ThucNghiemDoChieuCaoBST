#include<bits/stdc++.h>
#define fu(a,b,c) for(long long a=b;a<=c;a++)
#define fd(a,b,c) for(long long a=b;a>=c;a--)
#define Se second
#define Fi first
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;
ifstream fi ("DataSet10.OUT");
class Node
{
public:
    ll V;
    Node* L;
    Node* R;
    ll height;
    Node(ll val)
    {
        V=val;
        L=nullptr;
        R=nullptr;
        height=1;
    }
};
class AVL
{
public:
    Node* root;
    AVL()
    {
        root = nullptr;
    }
};
////////////////////////////////////////////////////
ll heig(Node* root)
{
    if(root==nullptr)
        return 0;
    return root->height;
}
ll balance(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return heig(node->L)-heig(node->R);
}
void update(Node* node)
{
    ll leftHeight=heig(node->L);
    ll rightHeight=heig(node->R);
    node->height=max(leftHeight, rightHeight) + 1;
}
////////////////////////////////////////////////////
Node* rotateright(Node* x)
{
    Node* y=x->L;
    Node* tmp=y->R;
    y->R=x;
    x->L=tmp;
    update(x);
    update(y);
    return y;
}
Node* rotateleft(Node* y)
{
    Node* x = y->R;
    Node* tmp = x->L;
    x->L = y;
    y->R = tmp;
    update(y);
    update(x);
    return x;
}
/////////////////////////////////////////////////////
Node* add(Node* root,ll x)
{
    if (root==nullptr)
    {
        return new Node(x);
    }
    if (x<root->V)
    {
        root->L=add(root->L,x);
    }
    else if(x>root->V)
    {
        root->R=add(root->R,x);
    }
    else
    {
        return root;
    }
    update(root);
    ll bal=balance(root);

    if(bal>1&&x<root->L->V)
    {
        return rotateright(root);
    }
    if(bal<-1&&x>root->R->V)
    {
        return rotateleft(root);
    }
    if(bal>1&&x>root->L->V)
    {
        root->L = rotateleft(root->L);
        return rotateright(root);
    }
    if(bal<-1&&x<root->R->V)
    {
        root->R = rotateright(root->R);
        return rotateleft(root);
    }
    return root;
}
//////////////////////////////////////////////////////
ll treeheig(Node* root)
{
    if (root==nullptr)
    {
        return 0;
    }
    ll leftheig=treeheig(root->L);
    ll rightheig=treeheig(root->R);
    return max(leftheig,rightheig)+1;
}
AVL A;
ll n;
int main()
{

    fi>>n;
    fu(i,1,n)
    {
        ll a;
        fi>>a;
        A.root = add(A.root,a);
    }
    cout<<treeheig(A.root);
}
