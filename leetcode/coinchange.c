/*

You are given an integer array coins representing coins of 
different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

*/
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "mysort.h"


/**
 *  Filter in-place, remove elements above threshold.
 *  Returns the new length of the array after filtering. 
 *  IMPORTANT: It is the job of the caller to clear out the remaining elements above the new length, if necessary. 
 */
int filter_above(int *a, const int len, const int threshold) {
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (a[j] <= threshold) {
            a[i++] = a[j];
        }
    }
    return i;
}

int coinChangeHelperSorted(int* coins, int coinsSize, int amount) {
    coinsSize = filter_above(coins, coinsSize, amount);
    mysort(coins, coinsSize); 

    int dp[amount + 1];
    dp[0] = 0;  // Base case: 0 coins needed to make amount 0
    int coin;
    int remainder;

    for (int i = 1; i <= amount; i++) {
        dp[i] = -1;
        for (int j = 0; j < coinsSize; j++) {
            coin = coins[j];
            if (coin > i) break;
            remainder = i - coin;
            if (remainder < 0) continue;
            if (dp[remainder] <= -1) continue;
            dp[i] = dp[i] < 0? dp[remainder] + 1: fmin(dp[i], dp[remainder] + 1);
        }
    }
    return dp[amount];
}


int coinChangeHelper(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    dp[0] = 0;  // Base case: 0 coins needed to make amount 0
    int coin;
    int remainder;

    for (int i = 1; i <= amount; i++) {
        dp[i] = -1;
        for (int j = 0; j < coinsSize; j++) {
            coin = coins[j];
            remainder = i - coin;
            if (remainder < 0) continue;
            if (dp[remainder] <= -1) continue;
            dp[i] = dp[i] < 0? dp[remainder] + 1: fmin(dp[i], dp[remainder] + 1);
        }
    }
    return dp[amount];
}


/**
 * Invariant: 1 <= coins.length <= 12
 * Invariant: 1 <= coins[i] <= 2^31 - 1
 * Invariant: 0 <= amount <= 10^4
 */
int coinChange(int* coins, int coinsSize, int amount) {
    return coinChangeHelperSorted(coins, coinsSize, amount);
}


int main(int argc, char *argv[]) 
{
    int target;
    int res;


    int case0[] = {1, 2, 5};
    target = 11;
    res = coinChange(case0, sizeof(case0)/sizeof(case0[0]), target);
    printf("case0 result coinChange(case0, %i, 11): %i\n", sizeof(case0)/sizeof(case0[0]), res);
    assert(res == 3);
    
    int case1[] = {2};
    target = 3;
    res = coinChange(case1, sizeof(case1)/sizeof(case1[0]), target);
    printf("case1 result coinChange(case1, %i, 3): %i\n", sizeof(case1)/sizeof(case1[0]), res);
    assert(res == -1);

    int case2[] = {1};
    target = 0;
    res = coinChange(case2, sizeof(case2)/sizeof(case2[0]), target);
    printf("case2 result coinChange(case2, %i, 0): %i\n", sizeof(case2)/sizeof(case2[0]), res);
    assert(res == 0);

    int case3[] = {474, 83, 404, 3};
    target = 264;
    res = coinChange(case3, sizeof(case3)/sizeof(case3[0]), target);
    printf("case3 result coinChange(case3, %i, 264): %i\n", sizeof(case3)/sizeof(case3[0]), res);
    assert(res == 8);

    return 0;
}