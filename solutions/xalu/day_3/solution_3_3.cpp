#include <iostream>

using namespace std;

typedef unsigned int uint;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
   ListNode *begin = NULL, *end;
   int buff = 0;
   while(a or b)
   {
      int a_value = 0;
      int b_value = 0;
      int sum = 0;
      if (a)
      {
       a_value =a->val;
       a = a->next;
      }
      if (b)
      {
       b_value = b->val;
       b = b->next;
      }
      sum = a_value + b_value + buff;
      buff = sum/10;
      ListNode* next = new ListNode(sum%10);
      if (begin)
      {
       end->next = next;
       end = next;
      }
      else
      {
       begin = next;
       end = next;
      }
   }
   if (buff)
      end->next = new ListNode(buff);
   return begin;
}

ListNode* createLN(int* nums, uint size){
   if (!size) return nullptr;
   ListNode* result = new ListNode(nums[0]),
           * list = result;
   for(uint i = 1; i < size; ++i) {
      list->next = new ListNode(nums[i]);
      list = list->next;
   }
   return result;
}

void printLN(ListNode *ln) {
   while(ln) {
      cout << ln->val << ' ';
      ln = ln->next;
   };
}
void deleteLN(ListNode *ln) {
   cout << "\ndelete: ";
   while(ln) {
      ListNode *next = ln->next;
      cout << ln->val << " ";
      delete ln;
      ln = next;
   }
}

int main() {
   int nums1[] = {5,4,3,2,1},
       nums2[] = {5,1};

   ListNode* ln1 = createLN(nums1,5),
           * ln2 = createLN(nums2,2);
   ListNode* result = addTwoNumbers(ln1,ln2);
   printLN(result);
   deleteLN(ln1);
   deleteLN(ln2);
   deleteLN(result);
   return 0;
}
