#include <stdio.h>

int findTargetSumWays(int* nums, int numsSize, int target) {

    int sum = 0;

    for(int i = 0; i < numsSize; i++)
        sum += nums[i];

    if((sum + target) % 2 != 0 || sum < abs(target))
        return 0;

    int S = (sum + target) / 2;

    int dp[S + 1];

    for(int i = 0; i <= S; i++)
        dp[i] = 0;

    dp[0] = 1;

    for(int i = 0; i < numsSize; i++) {

        for(int j = S; j >= nums[i]; j--) {

            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[S];
}