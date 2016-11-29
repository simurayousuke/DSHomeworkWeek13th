//
//  MaxHeap.h
//  DSHomeworkWeek13th
//
//  Created by 庄庄 on 2016/11/29.
//  Copyright © 2016年 YangZhiZhuang. All rights reserved.
//

#ifndef MaxHeap_h
#define MaxHeap_h

template<class T>
class MaxHeap
{
private:
    T* heapArray;
    int CurrentSize;
    int MaxSize;
    void expand()
    {
        T* larger=new T[MaxSize*3];
        MaxSize=MaxSize*3;
        for(int i=0;i<CurrentSize;++i)
            larger[i]=heapArray[i];
        heapArray=larger;
    }
public:
    MaxHeap(T* array,int num,int max)
    {
        MaxSize=max;
        heapArray=new T[MaxSize];
        
        CurrentSize=num;
        for(int i=0;i<num;++i)
            heapArray[i]=array[i];
        BuildHeap();
    }
    virtual ~MaxHeap(){};
    void BuildHeap()
    {
        for(int i=CurrentSize/2-1;i>=0;--i)
            SiftDown(i);
    }
    bool isLeaf(int pos)const
    {
        if(leftchild(pos)==-1&&rightchild(pos)==-1)
            return true;
        else
            return false;
    }
    int leftchild(int pos)const
    {
        if(2*pos+1<CurrentSize)
            return 2*pos+1;
        else
            return -1;
    }
    int rightchild(int pos)const
    {
        if(2*pos+2<CurrentSize)
            return 2*pos+2;
        else
            return -1;
    }
    int parent(int pos)const
    {
        return (int)((pos-1)/2);
    }
    void Remove(int pos,T& node)
    {
        T temp= heapArray[pos];
        node=temp;
        heapArray[pos]=heapArray[CurrentSize-1];
        heapArray[CurrentSize-1]=temp;
        --CurrentSize;
        int left,right;
        bool flag=true;
        while(flag)
        {
            left=leftchild(pos);
            right=rightchild(pos);
            if(left!=-1&&right!=-1)//2child
            {
                int max=heapArray[left]>heapArray[right]? left:right;
                if(heapArray[pos]<heapArray[max])
                {
                    T temp=heapArray[max];
                    heapArray[max]=heapArray[pos];
                    heapArray[pos]=temp;
                    pos=max;
                }
                else
                    flag=false;
            }
            else if(left==-1&&right==-1)//no child
            {
                flag=false;
            }
            else//only one child
            {
                int max=(left==-1)?right:left;
                if(heapArray[pos]<heapArray[max])
                {
                    T temp=heapArray[max];
                    heapArray[max]=heapArray[pos];
                    heapArray[pos]=temp;
                    pos=max;
                }
                else
                    flag=false;
            }
        }
    }
    void SiftDown(int pos)
    {
        int i=pos;
        int j=leftchild(i);
        T temp=heapArray[i];
        
        while(j<CurrentSize)
        {
            if((j<CurrentSize-1)&&(heapArray[j]<heapArray[j+1]))
                j++;
            if(temp<heapArray[j])
            {
                heapArray[i]=heapArray[j];
                heapArray[i]=temp;
                i=j;
                j=leftchild(i);
            }
            else
                break;
        }
    }
    void SiftUp(int position);
    void Insert(const T& newNode)
    {
        if(CurrentSize==MaxSize)
            expand();
        heapArray[CurrentSize]=newNode;
        int pos=CurrentSize++;
        while(heapArray[pos]>heapArray[parent(pos)]&&pos!=0)
        {
            T temp=heapArray[parent(pos)];
            heapArray[parent(pos)]=heapArray[pos];
            heapArray[pos]=temp;
            pos=parent(pos);
        }
    }
    void MoveMax();
    T RemoveMax()
    {
        T res;
        Remove(0,res);
        return res;
    }
    void print()
    {
        for(int i=0;i<CurrentSize;++i)
            std::cout<<heapArray[i]<<std::endl;
    }
};

#endif /* MaxHeap_h */
