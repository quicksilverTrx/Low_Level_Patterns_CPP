using namespace std;
#include <iostream>
#include <deque>
class Iterator{
    public:
    virtual int next() =0;
    virtual bool hasNext() = 0;
};
class SimpleIterator : public Iterator
{
    public:
    vector<int>::iterator current,end;
    SimpleIterator(){}
    SimpleIterator(vector<int>& vec): current(vec.begin()),end((vec.end())){}

    int next() override
    {
        int val = *current;
        current++;
        return val;
    }

    bool hasNext() override
    {
        return (current<end);
    }
};
// class OddIterator : public Iterator
// {
//     public:
//         SimpleIterator
// }
class StepIterator : public Iterator
{
    public:
    vector<int>::iterator current,end;
    int step;
    bool start;
    StepIterator(vector<int>&vec,int step=1): current(vec.begin()),end(vec.end()),step(step),start(true){}

    int next() override{
        int val= *(current);
        return val;
    }
    
    bool hasNext() override{
        if(start)
        {
            start=false;
            return (current<end);
        }
        int count = this->step;
        while(count>0&&current<end)
        {
            current++;
            count--;
        }
        if(count==0&&current<end)return true;
        return false;
    }
};
class BidirectionalIterator : public Iterator
{
    public:
    vector<int>::iterator start,current,end;
    bool direction;
    BidirectionalIterator(){}
    BidirectionalIterator(vector<int>&vec,bool direction=true) : start(vec.begin()),end(vec.end()),current(vec.begin()),direction(direction){}
    BidirectionalIterator(BidirectionalIterator &it): start(it.start),end(it.end),current(it.current),direction(!it.direction){}
    int getForward()
    {
        int val = *current;
        current++;
        return val;
    }

    int getBackward()
    {
        int val = *current;
        current--;
        return val;
    }
    int next() override
    {
        if(direction)
            return getForward();
        else
            return getBackward();
    }

    bool hasNext() override
    {
        if(direction)
        {
            return (current<end);
        }
        else
            return (current>=start);
    }

};
class InterleavingIteratorFromIterator : public SimpleIterator
{
    public:
    deque<SimpleIterator> dequeIterator;
    InterleavingIteratorFromIterator( vector<SimpleIterator>& iter)
    {
        for (auto it: iter)
        {
            if(it.hasNext())dequeIterator.push_back(it);
        }
    }
    int next() override
    {
        SimpleIterator temp = dequeIterator.front();
        dequeIterator.pop_front();
        
        if(temp.hasNext())
        {
            int val = (temp.next());
            if(temp.current<temp.end)dequeIterator.push_back(temp);
            return val;
        }
        return -1;
    }

    bool hasNext() override
    {
        return !(dequeIterator.empty());
    }
};
class CyclicIterator : public SimpleIterator
{
    public:
        vector<SimpleIterator> startIterators;
        deque<SimpleIterator> dequeIterators;
        CyclicIterator(vector<vector<int>> &input)
        {
            for (vector<int>&vec: input)
            {
                SimpleIterator it = SimpleIterator(vec);
                if(it.hasNext())
                {
                    startIterators.push_back(it);
                    dequeIterators.push_back(it);
                }
            }
        }

        int next() override{
            if(dequeIterators.empty())
            {
                for(SimpleIterator it : startIterators)
                {
                    dequeIterators.push_back(it);
                }

            }
            SimpleIterator temp = dequeIterators.front();
            dequeIterators.pop_front();
            int val = temp.next();
            if(temp.hasNext())
            {
                dequeIterators.push_back(temp);
            }
            return val;
        }

        bool hasNext() override
        {
            return !(dequeIterators.empty());
        }
};
class InterleavingIterator : public Iterator
{
    public:
    deque<SimpleIterator> iterator;
    
    InterleavingIterator( vector<vector<int>>&vec)
    {
        for (vector<int>&childVec : vec)
        {
            SimpleIterator it = SimpleIterator(childVec);
            if (it.hasNext())
            {
                iterator.push_back(it);
            }
        }
    }
    int next() override
    {
        SimpleIterator it = iterator.front();
        iterator.pop_front();
        int val= it.next();
        if(it.hasNext())
        {
            iterator.push_back(it);
        }
        return val;
    }

    bool hasNext() override
    {
        return !(iterator.empty());
    }
};
int main() 
{
    vector<int> arr1 ={1,2,3,4,5,6,7};
    SimpleIterator iter = SimpleIterator(arr1);
    while(iter.hasNext())
    {
        cout<<iter.next()<<" ";
    }
    cout<<"\n";
     vector<vector<int>> arr = {{1,2}, {11,12,13}, {}, {21,22,23}};
    InterleavingIterator iter1 = InterleavingIterator(arr);
    while(iter1.hasNext())
    {
        cout<<iter1.next()<<" ";
    }
    cout<<"\n";
    vector<SimpleIterator> iterator_vec;
    for (vector<int> &c:arr)
    {
        iterator_vec.push_back(SimpleIterator(c));
    }
    InterleavingIteratorFromIterator iter2 = InterleavingIteratorFromIterator(iterator_vec);
    while(iter2.hasNext())
    {
        cout<<iter2.next()<<" ";
    }
    cout<<"\n";
    CyclicIterator iter3 = CyclicIterator(arr);
    int count = 25;
    while(count-->0)
    {
        cout<<iter3.next()<<" ";
    }
    cout<<"\n";
    BidirectionalIterator iter4 = BidirectionalIterator(arr1);
    count=3;
    while(iter4.hasNext()&&count-->0)
    {
        cout<<iter4.next()<<" ";
    }
    cout<<"\n";
    BidirectionalIterator iter5 = BidirectionalIterator(iter4);
    while(iter5.hasNext())
    {
        cout<<iter5.next()<<" ";
    }
    cout<<"\n";
    StepIterator iter6 = StepIterator(arr1);
    while(iter6.hasNext())
    {
        cout<<iter6.next()<<" ";
    }
    cout<<"\n";
    StepIterator iter7 = StepIterator(arr1,2);
    while(iter7.hasNext())
    {
        cout<<iter7.next()<<" ";
    }
}