#include <iostream>
//#include <iterator>
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
    //cout << "Size = " << size << endl;
    
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

ListNode* sumLists(ListNode* list1, ListNode* list2)
{
    int sum;
    int digit;
    int upper = 0 ;

    if (!list1 && !list2) return NULL;
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }

    ListNode* list = new ListNode(0);
    ListNode* res = list;

    while (list1 || list2 || upper) {
        if (list1 && list2) {
            sum = list1->val + list2->val + upper;
            list1 = list1->next;
            list2 = list2->next;
        } else {
            if (list1) {
                sum = list1->val + upper;
                list1 = list1->next;
            } else if (list2)  {
                sum = list2->val + upper;
                list2 = list2->next;
            } else if (upper) {
                sum = upper;
            }
        }

        digit = sum%10;
        upper = sum/10;
        list->val = digit;

        prnList(list);

        if (list1 || list2 || upper) {
            list->next  = new ListNode(0);
            list = list->next;
        }
    }
    return res;
}

int main()
{
    vector<int> arr1 = {9,7,5};
    vector<int> arr2 = {3,2};
    
    ListNode *lst1 = array2list(arr1);
    ListNode *lst2 = array2list(arr2);
    prnList(lst1);
    prnList(lst2);
    ListNode *summed = sumLists(lst1,lst2);
    prnList(summed);
    clearList(summed);
    clearList(lst2);
    clearList(lst1);

    return 0;
}
