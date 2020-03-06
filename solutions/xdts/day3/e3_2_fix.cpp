#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* array2list(vector<int> nums)
{
    int size = nums.size();

    if (!size) return nullptr;

    ListNode* result = new ListNode(nums[0]);
    ListNode* list = result;

    for(int i = 1; i < size; ++i) {
        list->next = new ListNode(nums[i]);
        list = list->next;
    }
    return result;
}

void prnList(ListNode *list)
{
    while(list) {
        cout << list->val << " ; ";
        list = list->next;
    };
    cout << endl;
}

void clearList(ListNode *list)
{
    while(list) {
        ListNode* nextList = list->next;
        delete list;
        list = nextList;
    };
}

ListNode* mergeLists(ListNode* list1, ListNode* list2)
{

    if (!list1 && !list2) return NULL;
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    ListNode* list = new ListNode(0);
    ListNode* res = list;

    while (list1 || list2) {
        if (list1 && list2) {
            if (list1->val < list2->val) {
                list->val = list1->val;
                list1 = list1->next;
            } else {
                list->val = list2->val;
                list2 = list2->next;
            }
        } else {
            if (list1) {
                list->val = list1->val;
                list1 = list1->next;
            } else  {
                list->val = list2->val;
                list2 = list2->next;
            }
        }
        prnList(list);
        if (list1 || list2 ) {
            list->next  = new ListNode(0);
            list = list->next;
        }
    }
    return res;
}

int main()
{
    vector<int> arr1 = {1,2,4};
    vector<int> arr2 = {1,3,4};
    ListNode *lst1 = array2list(arr1);
    ListNode *lst2 = array2list(arr2);
    prnList(lst1);
    prnList(lst2);
    ListNode *merged = mergeLists(lst1,lst2);
    prnList(merged);
    clearList(merged);
    clearList(lst2);
    clearList(lst1);

    return 0;
}
