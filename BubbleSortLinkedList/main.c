//
//  main.c
//  BubbleSortLinkedList
//
//  Created by chenyufeng on 16/2/26.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  使用链表实现冒泡排序
 算法实现如下：
 （1）使用尾插法建立一个链表；
 （2）对该链表进行冒泡排序（主要考虑如何交换两个链表节点）；
 （3）打印排序后的链表；
 */

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef int elemType;
//构造节点
typedef struct ListNode{
    int element;
    struct ListNode *next;
}Node;

//初始化链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，头结点初始化完成\n",__FUNCTION__);
}

//打印链表
void printList(Node *pNode){
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//尾插法建立链表
Node *TailInsert(Node *pNode){

    Node *pInsert; //要插入的节点
    Node *pMove; //遍历链表的节点
    pInsert = (Node*)malloc(sizeof(Node));
    if (pInsert == NULL) {
        printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    memset(pInsert, 0, sizeof(Node));
    scanf("%d",&(pInsert->element));
    pInsert->next = NULL;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据有误，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    pMove = pNode;
    while (pInsert->element > 0) {
        if (pNode == NULL) {
            //注意不要忘了修改pMove指针的指向，初始pMove一定要指向头节点
            pNode = pInsert;
            pMove = pNode;
        }else{
            //遍历找到最后一个节点
            while (pMove->next != NULL) {
                pMove = pMove->next;
            }
            pMove->next = pInsert;
        }

        pInsert = (Node*)malloc(sizeof(Node));
        if (pInsert == NULL) {
            printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
            return NULL;
        }

        memset(pInsert, 0, sizeof(Node));
        scanf("%d",&(pInsert->element));
        pInsert->next = NULL;
    }

    printf("%s函数执行，尾插法建立链表成功\n",__FUNCTION__);

    return pNode;
}

//获取链表长度
elemType sizeList(Node *pNode){

    int i = 0;
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，长度为0\n",__FUNCTION__);
        return 0;
    }else{
        while (pNode != NULL) {

            i++;
            pNode = pNode->next;
        }
        printf("%s函数执行，链表长度为%d\n",__FUNCTION__,i);
        return i;
    }
}

//链表实现冒泡排序
Node *BubbleSortLinkedList(Node *pNode){
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，冒泡排序失败\n",__FUNCTION__);
        return NULL;
    }else{

        Node *pMove;
        pMove = pNode;
        //需要进行(n-1)次遍历,控制次数
        int size = sizeList(pNode);
        for (int i = 0; i < size; i++) {
            while (pMove->next != NULL) {
                if (pMove->element > pMove->next->element) {
                    //只要交换这两个节点的element元素值就可以了
                    int temp;
                    temp = pMove->element;
                    pMove->element = pMove->next->element;
                    pMove->next->element = temp;
                }
                pMove = pMove->next;
            }
            //每次遍历结束，pMove重新移动到链表头部
            pMove = pNode;
        }
    }
    printf("%s函数执行，链表冒泡排序完成\n",__FUNCTION__);

    return pNode;
}

int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);

    //尾插法建立链表
    pList = TailInsert(pList);
    printList(pList);

    //冒泡排序
    pList = BubbleSortLinkedList(pList);
    printList(pList);
    
    return 0;
}













