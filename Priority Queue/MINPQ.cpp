#include<bits/stdc++.h>
using namespace std;

/*
3 main functions:
insert, remove, getmin for min priority queue.
P.Q needs a implementation of heap , which is COMPLETE BINARY TREE + SATISFIES HEAP ORDER PROPERTY


CBT can be saved as an array

add func: 
isEmpty():
getMin():
*/

class PQueue{
    vector<int> pq;

public:
    PQueue()
    {

    }


    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        //pq ki minm element kya hai
        //minm is always kept at root in cbt
        if(isEmpty()) return 0;
        return pq[0];
    }

    void insert(int element)
    {
        //atlast of vector push new element
        pq.push_back(element);
        // make min heap property satisfy
        //bottom up process

        int chidx = pq.size()-1;//got idx of element
        


        while(chidx > 0)
        {
            int paridx = (chidx-1)/2; //parent of element
            if(pq[chidx] < pq[paridx])
            {
                int tmp = pq[chidx];
                pq[chidx] = pq[paridx];
                pq[paridx] = tmp;
            }

            chidx = paridx;
            paridx = (chidx-1)/2;
        }
    }

    /*
        

    */
    int removeMin()
    {
        if(isEmpty()) return INT_MIN; //pq empty

        //store in ans 0th element
        int ans = pq[0];

        //update 0th element with last element
        pq[0] = pq[pq.size()-1];
        //delete last element
        pq.pop_back();

        //down-heapify
        int paridx = 0;
        int leftchildidx = 2*paridx +1;
        int rightchildidx = 2*paridx +2;

        while(leftchildidx < pq.size())
        {
            //minidx holds idx of element out of 3(parent, leftchild, rightchild) whose value is minm
            //this minidx element we have to swap with parent element
            int minidx = paridx;
            if(pq[minidx] > pq[leftchildidx])
            {
                minidx = leftchildidx;
            }

            if(rightchildidx < pq.size() and pq[rightchildidx] < pq[minidx])
            {
                minidx = rightchildidx;
            }

            if(minidx == paridx)
            {
                break;
            }

            //swapping values
            int tmp = pq[minidx];
            pq[minidx] = pq[paridx];
            pq[paridx] = tmp;


            //niche and further children pe same process propagate
            paridx = minidx;
            leftchildidx = 2*paridx +1;
            rightchildidx = 2*paridx +2;

            //when to stop?
            //1.if lci > vector size , hmara element has bcome leaf in CBT, no further child
            //2. till minelement is parent only

        }
        return ans;
    }
};


void solve()
{
    PQueue p;

    p.insert(100); p.insert(200);
    p.insert(40);
    p.insert(4);
    p.insert(67);
    p.insert(21);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty())
    {
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;
    //above is non decreasing heap sort

}

signed main()
{
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
