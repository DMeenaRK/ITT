#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool checkPrimeFrequency(int* nums, int numsSize) {
    bool visited[101] = {false}; 

    for (int i = 0; i < numsSize; i++) {
        int currentNum = nums[i];

        if (visited[currentNum]) {
            continue;
        }
        visited[currentNum] = true;
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == currentNum) {
                count++;
            }
        }

        if (isPrime(count)) {
            return true; 
        }
    }

    return false;
}\