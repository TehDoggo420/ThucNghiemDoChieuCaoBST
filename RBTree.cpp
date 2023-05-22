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
    Node* P;
    char C;
    Node(ll val)
    {
        V=val;
        L=nullptr;
        R=nullptr;
        P=nullptr;
        C='R';
    }
};
Node* rotateleft(Node* y)
{
    Node* x = y->R;
    Node* tmp = x->L;
    x->L = y;
    y->R = tmp;
    y->P = x;
    if(tmp!=nullptr)
        tmp->P=y;
    return x;
}
Node* rotateright(Node* y)
{
    Node* x = y->L;
    Node* tmp= x->R;
    x->R = y;
    y->L = tmp;
    y->P = x;
    if(tmp!=nullptr)
        tmp->P=y;
    return x;
}
class RBTree
{
public:
    Node* Root;
    RBTree()
    {
        Root=nullptr;
    }
    bool rL=0,rR=0,rLR=0,rRL=0;
    Node* add(Node* root, ll val);
    void rotating(Node* root);
    void insert(ll val);

};
Node* RBTree::add(Node* root, ll val)
{
    if(root==nullptr)
    {
        return new Node(val);
    }
    else if(val==root->V)
    {
        return root;
    }
    ll needfix=0;
    if(val<root->V)
    {
        root->L = add(root->L,val);
        root->L->P=root;
        if(root!=Root && root->C=='R' && root->L->C=='R')
        {
            needfix=1;
        }
    }
    else if(val>root->V)
    {
        root->R = add(root->R,val);
        root->R->P=root;
        if(root!=Root && root->C=='R' && root->R->C=='R')
        {
            needfix=1;
        }
    }

//        if(needfix)
//        {
//            if(root==root->P->L)
//            {
//
//            }
//        }
    if(rL)
    {

        root=rotateleft(root);
        root->C='B';
        root->L->C='R';
        rL=0;
    }
    if(rR)
    {
        root=rotateright(root);
        root->C='B';
        root->R->C='R';
        rR=0;
    }
    if(rRL)
    {
        root->R = rotateright(root->R);
        root->R->P=root;
        root=rotateleft(root);
        root->C='B';
        root->L->C='R';
        rRL=0;
    }
    if(rLR)
    {
        root->L = rotateleft(root->L);
        root->L->P=root;
        root=rotateright(root);
        root->C='B';
        root->R->C='R';
        rLR=0;
    }
    if(needfix)
    {
        if(root->P!= nullptr && root==root->P->L)
        {
//                cout<<val;
            if(root->P->R==nullptr||root->P->R->C=='B' )
            {
                if(root->R!=nullptr && root->R->C == 'R' ) rLR=1;
                if(root->L!=nullptr && root->L->C == 'R' ) rR=1;
            }
            else
            {

                root->C='B';

                root->P->R->C='B';
                if(root->P !=Root)
                    root->P->C='R';
            }
            needfix=0;
//                if(root->P->R==nullptr)
        }
        else if(root->P!= nullptr && root==root->P->R)
        {
            if(root->P->L== nullptr||root->P->L->C == 'B')
            {

                if(root->R!=nullptr && root->R->C == 'R' ) rL=1;
                if(root->L!=nullptr && root->L->C == 'R' ) rRL=1;
            }
            else
            {

                root->P->L->C='B';
                if(root->P !=Root)
                    root->P->C='R';
                root->C= 'B';
            }
            needfix=0;
        }
    }
//        cout<<val;
    return root;
}
void RBTree::rotating(Node* root)
{
    if(rL)
    {

        root=rotateleft(root);
        root->C='B';
        root->L->C='R';
        rL=0;
    }
    if(rR)
    {
        root=rotateright(root);
        root->C='B';
        root->R->C='R';
        rR=0;
    }
    if(rRL)
    {
        root->R = rotateright(root->R);
        root->R->P=root;
        root=rotateleft(root);
        root->C='B';
        root->L->C='R';
        rRL=0;
    }
    if(rLR)
    {
        root->L = rotateleft(root->L);
        root->L->P=root;
        root=rotateright(root);
        root->C='B';
        root->R->C='R';
        rLR=0;
    }
}
void RBTree::insert(ll val)
{
    if(Root==nullptr)
    {
        Root= new Node(val);
        Root->V= val;
        Root->C= 'B';
        return;
    }
    Root= add(Root, val);
}
///////////////////////////
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
RBTree A;
ll n;
int main()
{
    fi>>n;

    fu(i,1,n)
    {
//        cout<<A.Root->V<<" ";
        ll a;
        fi>>a;
        A.insert(a);
    }

    cout<<treeheig(A.Root);
}
