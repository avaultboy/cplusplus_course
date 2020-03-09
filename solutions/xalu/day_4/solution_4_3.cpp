#include <iostream>
#include <vector>

using namespace std;
enum vectorId {
   none,
   first,
   second
};
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   //lengths of vectors
   int l1 = nums1.size(), l2 = nums2.size(), l3 = l1+l2;
   //indexes of l1 and l2
   int l1Id = 0, l2Id = 0;

   vectorId lastArr = none;
   bool ifN1 = (bool)l1, ifN2=(bool)l2;
   int n1 = ifN1?nums1[l1Id]:0, n2 = ifN2?nums2[l2Id]:0;

   if (l3%2) {
      int mId = l3/2;
      for (int id = 0; id <= mId; ++id) {
         if (!ifN2 or (ifN1 and n1 <= n2)) {
            lastArr = first;
            if (++l1Id < l1)
               n1 = nums1[l1Id];
            else
               ifN1 = false;
         }
         else
         {
            lastArr = second;
            if (++l2Id < l2)
               n2 = nums2[l2Id];
            else
               ifN2 = false;
         }
      }

      if (lastArr == first)
         return nums1[l1Id-1];
      else
         return nums2[l2Id-1];
   }
   else {
      int mId1 = l3/2-1,mId2 = l3/2;
      int m1,m2;
      for (int id = 0; id <= mId2; ++id) {
         if (!ifN2 or (ifN1 and n1 <= n2)) {
            lastArr = first;
            if (++l1Id < l1) n1 = nums1[l1Id];
            else ifN1 = false;
         }
         else {
            lastArr = second;
            if (++l2Id < l2) n2 = nums2[l2Id];
            else ifN2 = false;
         }
         if (id == mId1)
         {
         if (lastArr == first)
            m1 = nums1[l1Id-1];
         else
            m1 = nums2[l2Id-1];
         }
      }

      if (lastArr == first)
         m2 = nums1[l1Id-1];
      else
         m2 = nums2[l2Id-1];

      return (m1+m2)/2.0;
   }
   return -1;
}

int main()
{
   vector<int> n1{1,5};
   vector<int> n2{2,3,4};
   cout<< findMedianSortedArrays(n1,n2);
   return 0;
}