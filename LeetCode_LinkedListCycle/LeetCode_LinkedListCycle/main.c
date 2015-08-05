//
//  main.c
//  LeetCode_LinkedListCycle
//
//  Created by mac on 7/25/15.
//  Copyright (c) 2015 mac. All rights reserved.
//

#include <stdio.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
}ListNode, *lpListNode;

int hasCycle(struct ListNode *head);

int main(int argc, const char * argv[]) {
    return 0;
}
int hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }
    struct ListNode * fast = head->next;
    struct ListNode * slow = head;
    while (1) {
        if (fast->next == NULL) {
            return 0;
        }
        if (fast->next->next == NULL) {
            return 0;
        }
        if (fast == slow) {
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
}