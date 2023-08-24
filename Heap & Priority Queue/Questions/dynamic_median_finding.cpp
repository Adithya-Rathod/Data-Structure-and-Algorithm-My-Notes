#include<bits/stdc++.h>
using namespace std;
//TC {3,-2,-1} & {-2,-1,3} -cofilti karra thha
class minMax{
    priority_queue<int, vector<int>, greater<int>> minheap; 
    priority_queue<int> maxheap;

    public:
       void insert(int val)
        {
            if(maxheap.empty() || (!maxheap.empty() && val<=maxheap.top()) ||(!minheap.empty() && val<= minheap.top()))
                maxheap.push(val);
            else if(minheap.empty() || (!minheap.empty() && val>=minheap.top()) || (!maxheap.empty() && val>=maxheap.top()))
                minheap.push(val);
            
            if(maxheap.size() > minheap.size() + 1 && !maxheap.empty())
                {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                }
            if(minheap.size()>maxheap.size() && !minheap.empty())
            {
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        double median()
        {
            // display();
            if(!maxheap.empty())
                if(maxheap.size()== minheap.size()) //meaning even 
                    return (maxheap.top() + minheap.top())/2.0;
                else
                    return maxheap.top();
            else
                return 0;
        }
        // void display()
        // {
        //      priority_queue<int, vector<int>, greater<int>> heap1 = minheap; 
        //      priority_queue<int> heap2= maxheap;
        //     while(!heap1.empty())
        //         {
        //             cout<<heap1.top()<<" ";
        //             heap1.pop();
        //         }
        //     while(!heap2.empty())
        //         {
        //             cout<<heap2.top()<<" " ;
        //             heap2.pop();
        //         }
        //         cout<<endl; 
        // }
};
int main()
{
    vector<int> nums= {3,-2,-1};
    minMax heap;
    for(auto it : nums)
    {
        heap.insert(it);
    }
    
    cout<< heap.median();
return 0;
}