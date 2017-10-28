#include <iostream>
#define NUM_QUIZZES  5
#define NUM_STUDENTS 5
/**
 *
 *  给定一个含有n个元素的整型数组a，求a中所有元素的和。数组求和(递归方法)
 * @param a
 * @param n 如果数组元素个数为n，那么先求出前n-1个元素之和，再加上a[n - 1]即可
 * @return
 */
int sum(int*a, int n) {
    return n ==0?0 : sum(a, n -1) + a[n -1];
}


/**
 * 读取一个5×5的整数数组
 *
 * 输入每个学生5门测试的成绩，一共有5个学生。然后计算每个学生的总分和平均分，
 * 以及每门测验的平均分、高分和低分
 *
 */
void studentScoreStatistics(){

    int grades[NUM_STUDENTS][NUM_QUIZZES];
    int high, low, quiz, student, total;

    for (student = 0; student < NUM_STUDENTS; student++) {
        printf("Enter grades for student %d: ", student + 1);
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
            scanf("%d", &grades[student][quiz]);
    }

    printf("\nStudent  Total  Average\n");
    for (student = 0; student < NUM_STUDENTS; student++) {
        printf("%4d      ", student + 1);
        total = 0;
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
            total += grades[student][quiz];
        printf("%3d     %3d\n", total, total / NUM_QUIZZES);
    }

    printf("\nQuiz  Average  High  Low\n");
    for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
        printf("%3d     ", quiz + 1);
        total = 0;
        high = 0;
        low = 100;
        for (student = 0; student < NUM_STUDENTS; student++) {
            total += grades[student][quiz];
            if (grades[student][quiz] > high)
                high = grades[student][quiz];
            if (grades[student][quiz] < low)
                low = grades[student][quiz];
        }
        printf("%3d    %3d   %3d\n", total / NUM_STUDENTS, high, low);
    }


}


// 求数组的最大值和最小值，返回值在maxValue和minValue
//void MaxandMin(int *a, int l, int r, int& maxValue, int& minValue) {
//
//    if(l == r) // l与r之间只有一个元素
//    {
//        maxValue = a[l] ;
//        minValue = a[l] ;
//        return ;
//    }
//
//    if(l + 1 == r) // l与r之间只有两个元素
//    {
//        if(a[l] >= a[r])
//        {
//            maxValue = a[l] ;
//            minValue = a[r] ;
//        }
//        else
//        {
//            maxValue = a[r] ;
//            minValue = a[l] ;
//        }
//        return ;
//    }
//
//    int m = (l + r) / 2 ; // 求中点
//
//    int lmax ; // 左半部份最大值
//    int lmin ; // 左半部份最小值
//    MaxandMin(a, l, m, lmax, lmin) ; // 递归计算左半部份
//
//    int rmax ; // 右半部份最大值
//    int rmin ; // 右半部份最小值
//    MaxandMin(a, m + 1, r, rmax, rmin) ; // 递归计算右半部份
//
////    maxValue = max(lmax, rmax) ; // 总的最大值
////    minValue = min(lmin, rmin) ; // 总的最小值
//}


/**
 * 数组的最大值和次小值
 * 给定一个含有n个元素的整型数组a，得到a中的最大值和次小值。
 * @param a 待查找的数组
 * @param left
 * @param right left和right是查找区间
 * @param max
 * @param second max和second存放结果
 */
void MaxandMin(int a[], int left, int right, int&max, int&second){
    if(left == right)
    {
        max = a[left] ;
        second = INT_MIN;
    }
    else if(left +1== right)
    {
        max = a[left] > a[right] ? a[left] : a[right] ;
        second = a[left] < a[right] ? a[left] : a[right] ;
    }
    else
    {
        int mid = left + (right - left) /2 ;

        int leftmax ;
        int leftsecond ;
        MaxandMin(a, left, mid, leftmax, leftsecond) ;

        int rightmax ;
        int rightsecond ;
        MaxandMin(a, mid +1, right, rightmax, rightsecond) ;

        if (leftmax > rightmax)
        {
            max = leftmax ;
            second = leftsecond > rightmax ? leftsecond : rightmax ;
        }
        else
        {
            max = rightmax ;
            second = leftmax < rightsecond ? rightsecond : leftmax ;
        }

//        std::cout << "max-->" + max << std::endl;

    }
}



// 找出两个数组的共同元素
void FindCommon(int* a, int* b, int n) {
    int i = 0;
    int j = 0 ;

    while (i < n && j < n)
    {
        if (a[i] < b[j])
            ++i ;
        else if(a[i] == b[j])
        {
            std::cout << a[i] << std::endl ;
            ++i ;
            ++j ;
        }
        else// a[i] > b[j]
            ++j ;
    }
}

/**
 * 合并两个有序数组
 * 给定含有n个元素的两个有序数组a和b。合并两个数组中的元素到整型数组c，要求去除重复元素并保持c有序。
 * @param a
 * @param b
 * @param c
 * @param n
 */
void Merge(int *a, int *b, int *c, int n){
    int i = 0 ;
    int j = 0 ;
    int k = 0 ;

    while (i < n && j < n)
    {
        if (a[i] < b[j])// 如果a的元素小，则插入a中元素到c
        {
            c[k++] = a[i] ;
            ++i ;
        }
        else if (a[i] == b[j])// 如果a和b元素相等，则插入二者皆可，这里插入a
        {
            c[k++] = a[i] ;
            ++i ;
            ++j ;
        }
        else // a[i] > b[j] // 如果b中元素小，则插入b中元素到c
        {
            c[k++] = b[j] ;
            ++j ;
        }
    }

    if (i == n) // 若a遍历完毕，处理b中剩下的元素
    {
        for (int m = j; m < n; ++m)
            c[k++] = b[m] ;
    }
    else//j == n, 若b遍历完毕，处理a中剩下的元素
    {
        for (int m = i; m < n; ++m)
            c[k++] = a[m] ;
    }


}


int main(void) {

//    std::cout << "Hello, World!" << std::endl;

//    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    //定义并初始化了数组array
//    int array[100] = {5, 200 , 3, 201};

    //分配了长度为100的数组array
//    int* array = new int[100];


    //为长度为100的数组array初始化前两个元素
//    int* array = new int[100](1, 2);

    //数组初始化了array[0][0,1]及array[1][0,1]
//    int array[10][10] = { {1,1} , {2,2} };

    /**
     * har类型的数组被常委字符数组，在字符数组中最后一位为转移字符'\0'（也被成为空字符），
     * 该字符表示字符串已结束。在C++中定义了string类，在Visual C++中定义了Cstring类。
       字符串中每一个字符占用一个字节，再加上最后一个空字符。
     */
//    char array[10] = "cnblogs"; //虽然只有7个字节，但是字符串长度为8个字节。

//    char array[] = "cnblogs";  //也可以不用定义字符串长度


//    int mSum = sum(array, 4);

//    std::cout << mSum << std::endl;

//    int a[100] = {0, 1, 2, 3, 4};
//    int b[100] = {1, 3, 5, 7, 9};
//    int c[100] = {11, 3, 15, 17, 9};
//
//    Merge(a, b, c, 5);

    studentScoreStatistics();




    return 0;
}

