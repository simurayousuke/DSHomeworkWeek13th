//
//  main.cpp
//  DSHomeworkWeek13th
//
//  Created by 庄庄 on 2016/11/29.
//  Copyright © 2016年 YangZhiZhuang. All rights reserved.
//

#include <iostream>
#include "MaxHeap.h"

int main()
{
    int values1[5]={20,15,2,13,10};
    int values2[6]={21,20,15,13,10,2};
    MaxHeap<int> maxHeap1(values1,5,7);//P118的例子
    MaxHeap<int> maxHeap2(values2,6,7);//P119的例子
    int temp;
    for(int i=0;i<6;++i)
    {
        maxHeap2.Remove(0, temp);
        std::cout<<temp<<std::endl;
    }
    /*
    std::cout<<"Insert 21"<<std::endl;
    maxHeap1.Insert(21);
    maxHeap1.print();
    std::cout<<"Remove Max"<<std::endl;
    maxHeap2.RemoveMax();
    maxHeap2.print();
     */
    return 0;
}
