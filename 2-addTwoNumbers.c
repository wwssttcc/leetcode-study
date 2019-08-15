/*
题目描述：
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

解题思路：
该题可以用于大数相加，利用两个链表相加；
1.两链表最大数相加9 + 9 + 1 = 19，所以进位最大为1；
2.当到达链表尾时，可以将数值设为0，这样一个循环就可以完成；
*/
#if 0
struct ListNode{
    int val;
    struct ListNode *next;
};
#endif

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p3, *p, *p1, *p2, *l3, *head;
    int len1 = 0, len2 = 0, len, result = 0;
    int num_p = 0;
    int a,b;
    p1 = l1;
    p2 = l2;

    //创建链表头
    p3 = l3 = malloc(sizeof(struct ListNode));
    p3->val = 0;
    while(p1 != NULL || p2 != NULL)
    {
        a = (p1 != NULL) ? p1->val : 0;
        b = (p2 != NULL) ? p2->val : 0;
        p3->next = malloc(sizeof(struct ListNode));
        p3 = p3->next;
        result = a + b + result / 10;
        p3->val = result % 10;
        
        if(p1 != NULL)
            p1 = p1->next;
        if(p2 != NULL)
            p2 = p2->next;
        
    }

    if(result > 9)
    {
        p3->next = malloc(sizeof(struct ListNode));
        p3 = p3->next;
        p3->val = result / 10;
    }
    
    p3->next = NULL;
    
    return l3->next;
}