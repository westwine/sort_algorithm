#include<bits/stdc++.h>

using namespace std;

class Sort {
private :
    void quick(vector<int>&, int, int);
    void merge(vector<int>&, int, int, int, int);
    void maxHeapify(vector<int>&, int, int);
public :
    int method = 6;
    static void print(vector<int>&);

    void bubbleSort(vector<int>&);
    void insertSort(vector<int>&);
    void selectSort(vector<int>&);
    
    void quickSort(vector<int>&);
    void mergeSort(vector<int>&, int, int);
    void heapSort(vector<int>&);

    void countSort();
    void bucketSort();
    void radixSort();
    void sortMethod(vector<int>& nums, int mode) {
        switch(mode) {
            case 0 :
                bubbleSort(nums);
                break;
            case 1 :
                insertSort(nums);
                break;
            case 2 :
                selectSort(nums);
                break;
            case 3 :
                quickSort(nums);
                break;
            case 4 :
                mergeSort(nums, 0, nums.size() - 1);
                cout << "merge sort result :";
                print(nums);
                break;
            case 5 :
                heapSort(nums);
                cout << "heap sort result :";
                print(nums);
                break;
            default :
                bubbleSort(nums);
        }
    }
    
};

void Sort::bubbleSort(vector<int>& nums) {
    for(int i = nums.size() - 1; i >= 0; -- i) {
        for(int j = 1; j <= i; ++ j) {
            if(nums[j - 1] > nums[j]) swap(nums[j - 1], nums[j]);
        }
    }
    cout << "bubble sort result :";
    print(nums);
}

void Sort::insertSort(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++ i) {
        for(int j = i; j >= 1; -- j) {
            if(nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
            else break;
        }
    }
    cout << "insert sort result :";
    print(nums);
}

void Sort::selectSort(vector<int>& nums) {
    int index = 0;
    while(index < nums.size() - 1) {
        int mmi = index;
        for(int i = index; i < nums.size(); ++ i) {
            if(nums[i] < nums[mmi]) {
                mmi = i;
            }
        }
        if(mmi != index) swap(nums[mmi], nums[index]);
        ++ index;
    }
    cout << "select sort result :";
    print(nums);
}

void Sort::quickSort(vector<int>& nums) {
    quick(nums, 0, nums.size() - 1);
    cout << "quick sort result :";
    print(nums);
}

void Sort::quick(vector<int>& nums, int start, int end) {
    if(start >= end) return ;
    int l = start, r = end;
    int val = nums[start];
    while(l < r) {
        while(l < r && nums[r] > val) -- r;
        if(l < r) swap(nums[r], nums[l ++]);
        while(l < r && nums[l] < val) ++ l;
        if(l < r) swap(nums[r --], nums[l]);
    }
    nums[l] = val;
    quick(nums, start, l - 1);
    quick(nums, l + 1, end);
}

void Sort::mergeSort(vector<int>& nums, int left, int right) {
    if(left >= right) return ;
    int mid = (left + right) >> 1;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, mid + 1, right);
    // cout << "merge sort result :";
    // print(nums);
}

void Sort::merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
    vector<int> sorted(r1 - l1 + 1 + r2 - l2 + 1);
    int index1 = l1, index2 = l2, index = 0;
    while(index1 <= r1 || index2 <= r2) {
        if(index1 > r1 || index2 <= r2 && nums[index1] > nums[index2]) {
            sorted[index] = nums[index2 ++];
        }
        else sorted[index] = nums[index1 ++];
        ++ index;
    }
    -- index;
    for(int i = r2; i >= l2; -- i) {
        nums[i] = sorted[index --];
    }
    for(int i = r1; i >= l1; -- i) {
        nums[i] = sorted[index --];
    }
}

void Sort::heapSort(vector<int>& nums) {
    for(int i = nums.size() / 2 - 1; i >= 0; -- i) {
        maxHeapify(nums, i, nums.size() - 1);
    }
    for(int i = nums.size() - 1; i >= 0; -- i) {
        swap(nums[i], nums[0]);
        maxHeapify(nums, 0, i - 1);
    }
}

void Sort::maxHeapify(vector<int>& nums, int start, int end) {
    if(start >= end) return ;
    int left = start * 2, right = start * 2 + 1;
    int which = start;
    if(left <= end && nums[left] > nums[which]) which = left;
    if(right <= end && nums[right] > nums[which]) which = right;
    if(which != start) {
        swap(nums[which], nums[start]);
        maxHeapify(nums, which, end);
    }
}

void Sort::print(vector<int>& nums) {
    for(int num : nums)
        cout << num << " ";
    cout << endl;
}