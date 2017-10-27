#include <iostream>

// 数组求和
int sum(int*a, int n) {
    return n ==0?0 : sum(a, n -1) + a[n -1];
}



// 求数组的最大值和最小值，返回值在maxValue和minValue
void MaxandMin(int *a, int l, int r, int& maxValue, int& minValue) {

    if(l == r) // l与r之间只有一个元素
    {
        maxValue = a[l] ;
        minValue = a[l] ;
        return ;
    }

    if(l + 1 == r) // l与r之间只有两个元素
    {
        if(a[l] >= a[r])
        {
            maxValue = a[l] ;
            minValue = a[r] ;
        }
        else
        {
            maxValue = a[r] ;
            minValue = a[l] ;
        }
        return ;
    }

    int m = (l + r) / 2 ; // 求中点

    int lmax ; // 左半部份最大值
    int lmin ; // 左半部份最小值
    MaxandMin(a, l, m, lmax, lmin) ; // 递归计算左半部份

    int rmax ; // 右半部份最大值
    int rmin ; // 右半部份最小值
    MaxandMin(a, m + 1, r, rmax, rmin) ; // 递归计算右半部份

//    maxValue = max(lmax, rmax) ; // 总的最大值
//    minValue = min(lmin, rmin) ; // 总的最小值
}

int main() {

//    std::cout << "Hello, World!" << std::endl;

//    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    //定义并初始化了数组array
    int array[100] = {1, 200 , 3, 12};

    //分配了长度为100的数组array
//    int* array = new int[100];


    //为长度为100的数组array初始化前两个元素
//    int* array = new int[100](1, 2);

    //数组初始化了array[0][0,1]及array[1][0,1]
//    int array[10][10] = { {1,1} , {2,2} };

    int m = 3;

    /**
     * har类型的数组被常委字符数组，在字符数组中最后一位为转移字符'\0'（也被成为空字符），
     * 该字符表示字符串已结束。在C++中定义了string类，在Visual C++中定义了Cstring类。
       字符串中每一个字符占用一个字节，再加上最后一个空字符。
     */
//    char array[10] = "cnblogs"; //虽然只有7个字节，但是字符串长度为8个字节。

//    char array[] = "cnblogs";  //也可以不用定义字符串长度


    int mSum = sum(array, 4);

    std::cout << mSum << std::endl;

    return 0;
}

