//合并两个有序链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) 
        return l2;//l1无参赛资格直接淘汰，l2获胜
    if (l2 == NULL)
        return l1;//l2无参赛资格直接淘汰，l1获胜

    if (l1->val > l2->val) {//l2获胜，得到本场胜利，排名第一
        //等号前：第二名会是谁呢 等号后：l1将和l2的下一位选手进行下一场比赛，决出第二名
        l2->next = mergeTwoLists(l1, l2->next);
        //本场胜者第一名l2回后台休息
        return l2;
    } else {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
}

#if 0
分析：
从两条链表的首结点开始比较，将比较小的那个“加入新链表”，将本次比较大的结点值与 比较小的结点的next结点再进行比较，将比较小的那个 “加入新链表”

函数体：
比较大小，将小的加入新链表

返回值：
返回较小的结点

本次调用和下次调用建立联系：
本次调用得出的较小值的next = 下次调用得到的较小值。
下次的调用的入参：本次的较小者的next和本次的较大者

终止条件：
其中一个null，意味着某条链已经没有结点了，后续的就不用再比较了
#endif