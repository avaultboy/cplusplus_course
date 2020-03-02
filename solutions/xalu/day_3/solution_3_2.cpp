#include <iostream>

using namespace std;

typedef unsigned int uint;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
   if (!l1 and !l2) return NULL;
   ListNode* result  = new ListNode(0);
   ListNode* result_beg = result;
   while(l1 or l2)
   {
      if (l1 and l2)
      {
         if (l1->val <= l2->val)
         {
            result->val = l1->val;
            l1 = l1->next;
            //cout << result->val << endl;
         }
         else
         {
            result->val = l2->val;
            //cout << result->val << endl;
            l2 = l2->next;
         }
      }
      else
      {
         if (l1)
         {
            result->val = l1->val;
            l1 = l1->next;
            //cout << result->val << endl;
         }
         if (l2)
         {
            result->val = l2->val;
            l2 = l2->next;
            //cout << result->val << endl;
         }
      }
      if (l1 or l2)
      {
         result->next = new ListNode(0);
         result = result->next;
      }
   }

   return result_beg;
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

int main()
{
   int l1_i[] = {1,2,4};
   int l2_i[] = {1,3,4};
   ListNode *l1 = createLN(l1_i,3),
            *l2 = createLN(l2_i,3);

   ListNode *ln = mergeTwoLists(l1,l2);
   printLN(ln);
   deleteLN(ln);
   deleteLN(l1);
   deleteLN(l2);
   return 0;
}
