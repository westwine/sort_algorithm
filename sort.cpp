#include <bits/stdc++.h>
#include "Sort.h"

using namespace std;


int main() {
    Sort my_sort;
    int num = 11;
    // cin >> num;
    vector<int> nums{2,5,6,8,2,4,1,423,42,553,43};
    vector<int> tmp;
    // for(int i = 0; i < num; ++ i) cin >> nums[i];
    cout << "original num vector :";
    my_sort.print(nums);
    int total = my_sort.method, cnt = 0;
    while(cnt < total) {
        tmp = nums;
        cout << cnt << endl;
        my_sort.sortMethod(tmp, cnt ++);
        //print(nums);
    }
    getchar();
    return 0;
}