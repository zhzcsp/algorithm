/*
 * Filename   Median_of_Two_sorted_Arrays.cc
 * CreateTime 2019-02-16 09:26:41
 * 
 * Copyright  (C) Zhao Huanzhen
 * Copyright  (C) zhzcsp@gmail.com
 */

#include <iostream>
#include <algorithm>
using namespace std;

//There are two sorted arrays A and B of size m and n respectively. 
//Find the median of the two sorted arrays.
//

class Solution {
public:
    int medianOfSortedAarray(int A[], int m, int B[], int n)
    {
        int total = m + n;   
        if (total &0x01)
            return find_kth(A,m, B, n, total/2 + 1);
        else
            return (find_kth(A,m,B,n, total/2) + find_kth(A,m,B,n, total/2 + 1)) / 2;
    }

private:
    int find_kth(int A[], int m, int B[], int n, int k)
    {
        // assume always that m is el than n;
        if (m > n)  return find_kth(B, m, A, n, k);
        if (m == 0) return B[k-1];
        if (k==1) return min(A[0], B[0]);
        
        //if (A[k/2 -1] < B[k/2 - 1])
        int ia = min(k/2, m), ib = k - ia;
        if (A[ia-1] < B[ib -1])
            return find_kth(A+ia, m-ia, B, n, k-ia);
        else if (A[ia-1] > B[ib-1])
            return find_kth(A,m, B+ib, n-ib, k-ib);
        else
            return A[ia-1];

    }
};
