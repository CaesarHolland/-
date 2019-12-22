/*
    输入下标统一从1开始计算 
*/
#include<iostream>
using namespace std;
int tmp[100010];
// #define enter(i,n) for(int i=1 ; i<=n ; i++) cin>>arr[i];

void insertSort(int *arr , int n);
void BinInsertSort(int *arr , int n);
void shellSort(int *arr , int n);
void bubbleSort(int *arr , int n);
void quick_sort(int q[], int l, int r);
void mergesort(int *arr , int a , int b);
void selectSort(int *arr , int n);
void heapSort(int *arr , int n);
void print(int *arr , int n);
void enter(int *arr , int n);

int main()
{
    int n;
    cin>>n;
    int arr[n];
    enter(arr,n);
    // BinInsertSort(arr,n);
    // shellSort(arr,n);
    // bubbleSort(arr,n);
    // quick_sort(arr,1,n);
    // mergesort(arr,1,n);
    // selectSort(arr,n);
    // heapSort(arr,n);
    print(arr,n);
    return 0;
}


//堆排序
void sift(int *arr, int low , int high){
    int i=low , j=2*i;
    int tmp = arr[i];
    while(j<=high)
    {
        if(j<high && arr[j]<arr[j+1]) j++;
        if(tmp<arr[j]){
            arr[i] = arr[j];
            i=j;
            j = 2*i;
        }
        else break;
    }
    arr[i] = tmp;
}
void heapSort(int *arr , int n){
    int i;
    for(i=n/2 ; i>=1 ; i--){
        sift(arr,i,n);
    }
    for(i=n ; i>=2 ; i--){
        swap(arr[1] , arr[i]);
        sift(arr,1,i-1);
    }
}

//简单选择排序
void selectSort(int *arr , int n){
    int i,j,k;
    for(i=1 ; i<n ; i++){
        k=i;
        for(j=i+1 ; j<=n ; j++)
            if(arr[j]<arr[k])
                k = j;
        if(k!=i)
            swap(arr[i] , arr[k]);
    }
}

//直接插入排序
void insertSort(int *arr , int n){
    int i , j;
    int temp;
    for(i=2 ; i<=n ; i++){
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            j = i-1;
            do{
                arr[j+1] = arr[j];
                j--;
            }while(j>=0 && arr[j]>temp);
            arr[j+1] = temp;
        }
    }
}

//折半插入排序
void BinInsertSort(int *arr , int n){
    int i , j , low , high , mid;
    int temp;
    for(i=2 ; i<=n ; i++){
        if(arr[i]<arr[i-1]){
            temp = arr[i];
            low = 1;
            high = i-1;
            while(low<=high){
                mid = (low+high)/2;
                if(temp<arr[mid]) high = mid-1;
                else low = mid+1;
            }
            for(j=i-1 ; j>=high+1 ; j--) arr[j+1]=arr[j];
            arr[high+1] = temp;
        }
    }
}

//希尔排序
void shellSort(int *arr , int n){
    int d = n/2;
    int i,j,temp;
    while(d>0){
        for(i=d+1 ; i<=n ; i++){
            temp = arr[i];
            j = i - d;
            while(j>=1 && temp<arr[j]){
                arr[j+d] = arr[j];
                j = j - d;
            }
            arr[j+d] = temp;
        }
        d = d/2;
    }
}

//冒泡排序
void bubbleSort(int *arr , int n){
    for(int i=1 ; i<=n ; i++)
        for(int j=n ; j>i ; j--)
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
}

//快速排序
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

//归并排序
void mergesort(int *arr , int a , int b){
    if(a>=b) return;

    int mid = (a+b)>>1;
    mergesort(arr,a,mid);
    mergesort(arr,mid+1,b);
    int i=a , j=mid+1 , k=0;
    while(i<=mid && j<=b){
        if(arr[i]<=arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=b) tmp[k++] = arr[j++];

    for(i=a , j=0 ; i<=b ; i++ , j++) arr[i] = tmp[j];
}

//附属组件
void print(int *arr , int n){
    for(int i=1 ; i<=n ; i++) cout<<arr[i]<<' ';
}
void enter(int *arr , int n){
    for(int i=1 ; i<=n ; i++)
        cin>>arr[i];
}