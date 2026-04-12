#include <assert.h>
#include <stdio.h>

int find_first_bar(int* height, int heightSize) {
    for (int i = 0; i < heightSize; i++) {
        if (height[i] > 0) {
            return i;
        }
    }
    return -1;
}

int find_next_geq_bar(int* height, int heightSize, int start_i) {
    int target = height[start_i];
    int next_i = -1;
    int next_i_height = 0;
    for (int i = start_i + 1; i < heightSize; i++) {
        if (height[i] >= target) {
            return i;
        } else if (height[i] > next_i_height) {
            next_i = i;
            next_i_height = height[i];
        }
    }
    return next_i;
}

int calculate_rainwater(int* height, int start_i, int next_i) {
    int min_height = height[start_i] < height[next_i] ? height[start_i] : height[next_i];
    int rainwater = 0;
    for (int i = start_i + 1; i < next_i; i++) {
        rainwater += (min_height - height[i]);
    }
    return rainwater;
}

// Worst case O(n^2)
int trap1(int* height, int heightSize) {
    int rainwater = 0;  
    int starting_i = find_first_bar(height, heightSize);
    int next_i = 0;
    if (starting_i == -1) {
        return rainwater; // No bars, no rainwater
    }
    while (starting_i < heightSize) {
        next_i = find_next_geq_bar(height, heightSize, starting_i);
        if (next_i == -1) {
            starting_i++;
            break;
        } else {
            rainwater += calculate_rainwater(height, starting_i, next_i);
            starting_i = next_i;
        }
    }
    return rainwater;
}


int trap2(int* height, int heightSize) {

}

int trap(int* height, int heightSize) {
    // return trap1(height, heightSize);
    return trap2(height, heightSize);
}



int main() {
    int case0[] = {1, 0, 1};
    int res = trap(case0, sizeof(case0)/sizeof(case0[0]));
    printf("case0 result trap(case0, %i): %i\n", sizeof(case0)/sizeof(case0[0]), res);
    assert(res == 1);
    

    int case1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(trap(case1, sizeof(case1)/sizeof(case1[0])) == 6);

    int case2[] = {4,2,0,3,2,5};
    assert(trap(case2, sizeof(case2)/sizeof(case2[0])) == 9);

    int case3[] = {4,9, 0,3,2,10,};
    assert(trap(case3, sizeof(case3)/sizeof(case3[0])) == 22);
}