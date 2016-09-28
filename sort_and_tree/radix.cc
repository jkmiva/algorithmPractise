// Copyright [2016] <Huang Jiaming>
/**
 * 关于排序,两种模式,一种是 comparison model, 最优复杂度是 O(nlogn),
 * 基于比较.比如 MERGE, QUICK,HEAP SORT.
 * for small integers, there are O(n) sorting, counting and radix.
 * n integers, k possible values.( k = n^{O(1)} )
 * build an array a[k], for each n, store counting number in a[k]
 *
 */
#include <iostream>
