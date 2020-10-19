#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
typedef int KeyType;
typedef int DataType;
#define MaxSize 60000
typedef struct entry
{
	KeyType key;//排序关键字
	DataType data;//其他数据项

}Entry;
typedef struct maxheap
{
	int n, MaxHeap;
	Entry D[MaxSize];
}MaxHeap;
typedef struct list
{
	int n;//元素个数
	Entry D[MaxSize];//静态数组
}List;
void InIt(MaxHeap *list, int nSize)
{
	list->n = nSize;
	for (int i = 0; i < nSize; i++)
	{
		list->D[i].key = (int)malloc(nSize * sizeof(int));
		list->D[i].key = 0;
	}
}
void InSert(MaxHeap *list, int nSize)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < nSize; i++)
	{
		list->D[i].key = (rand() % 100000+1);
	}
}
void InIt(List *list, int nSize)
{
	list->n = nSize;
	for (int i = 0; i < nSize; i++)
	{
		list->D[i].key = (int)malloc(nSize * sizeof(int));
		list->D[i].key = 0;
	}
}
void InSert(List *list, int nSize)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < nSize; i++)
	{
		list->D[i].key = (rand() % 100000+1);
	}
}
void swap(Entry* D, int i, int j)
{
	if (i == j)
		return;
	Entry temp = *(D + i);
	*(D + i) = *(D + j);
	*(D + j) = temp;
}
void AdjustDown(Entry *heap, int s, int m)
{
	Entry temp = heap[s];
	int j;
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&heap[j].key < heap[j + 1].key)
			j++;
		if (temp.key > heap[j].key)
			break;
		heap[s] = heap[j];
		s = j;

	}
	heap[s] = temp;
}

//简单选择排序
void SelectSort(List *list) {
	int small, i, j;
	for (i = 0; i < list->n - 1; i++) {
		small = i;                                    //标记每次第一位元素下标
		for (j = i + 1; j < list->n; j++) {
			if (list->D[j].key < list->D[small].key) {  //按非递减顺序比较大小
				small = j;
			}
		}

		if (small != i) {                               //判断起始位置是否为最小值
			swap(list->D, small, i);//本趟最小和本趟起点交换位置
		}
	}
}

//直接插入排序
void InsertSort(List *list)
{
	int i, j;                                 //i标识待插入元素下标
	for (i = 1; i < list->n; i++) {
		Entry insertItem = list->D[i];     //标记每次第一位元素
		for (j = i - 1; j >= 0; j--) {
			//不断将有序序列中元素向后移动,为待插入元素空出一个位置
			if (insertItem.key < list->D[j].key) {
				list->D[j + 1] = list->D[j];
			}
			else break;
		}
		list->D[j + 1] = insertItem;          //待插入元素有序存放至有序序列中
	}
}
//冒泡排序
void BubbleSort(List *list) {
	int i, j;                    //i标识每趟排序范围最后一个元素下标,每趟排序元素下标范围是0~i
	for (i = list->n - 1; i > 0; i--) {
		bool isSwap = false;    //教材这里错了,应该放到第二层循环前
		for (j = 0; j < i; j++) {
			if (list->D[j].key > list->D[j + 1].key) {
				swap(list->D, j, j + 1);
				isSwap = true;
			}
		}
		if (!isSwap) break;     //如果本趟排序没有发生元素交换,排序完成
	}
}
//序列划分方法
int Partition(List *list, int low, int high) {
	int i = low, j = high + 1;
	Entry pivot = list->D[low];                 //pivot是分割元素
	do {
		do i++;
		while (list->D[i].key < pivot.key);      //i前进
		do j--;
		while (list->D[j].key > pivot.key);      //j前进
		if (i < j) swap(list->D, i, j);
	} while (i < j);
	swap(list->D, low, j);
	return j;                                   //此时j是分割元素下标
}


//快速排序
void QuickSort(List *list, int low, int high) {   //快速排序的递归函数
	int k;
	if (low < high) {                            //当前待排序序列至少包含2个元素
		k = Partition(list, low, high);
		QuickSort(list, low, k - 1);
		QuickSort(list, k + 1, high);
	}
}


//函数重载
void QuickSort(List *list) {                   //快速排序算法的主调用函数
	QuickSort(list, 0, list->n - 1);
}
//Merge函数
void Merge(List *list, int Temp[], int i1, int j1, int i2, int j2, int *k) {
	int i = i1, j = i2;
	while ((i <= j1) && (j <= j2)) {                       //若两个子序列都不空,则循环
		if (list->D[i].key <= list->D[j].key) {
			Temp[(*k)++] = list->D[i++].key;         //将较小元素存入Temp[*k]
		}
		else Temp[(*k)++] = list->D[j++].key;
	}
	while (i <= j1) Temp[(*k)++] = list->D[i++].key;  //将子序列1中剩余元素存入Temp
	while (j <= j2) Temp[(*k)++] = list->D[j++].key;  //将子序列2中剩余元素存入Temp
}


//MergeSort函数、
void MergeSort(List *list) {
	int Temp[MaxSize];
	int i1, j1, i2, j2, i, k, size = 1;              //i1,j1和i2,j2分别是两个子序列的上,下界
	while (size < list->n) {
		i1 = 0;
		k = 0;
		while (i1 + size < list->n) {              //若i1+size < n,则说明存在两个子序列,需要再两两合并
			i2 = i1 + size;                      //确定子序列2的下界和子序列1的上界
			j1 = i2 - 1;
			if (i2 + size - 1 > list->n - 1) {         //设置子序列2的上界
				j2 = list->n - 1;
			}
			else j2 = i2 + size - 1;
			Merge(list, Temp, i1, j1, i2, j2, &k);  //合并相邻两个子序列
			i1 = j2 + 1;                        //确定下一次合并第一个子序列的下界
		}
		for (i = 0; i < k; i++) {
			list->D[i].key = Temp[i];
		}
		size *= 2;                            //子序列长度扩大一倍
	}
}
//堆排序算法
void HeapSort(MaxHeap *heap)
{
	int i;
	for (i = heap->n / 2; i >=0; i--)//改为>=0，否则第一个不参与堆调整
		AdjustDown(heap->D, i, heap->n);
	for (i = heap->n - 1; i > 0; i--)
	{
		swap(heap->D, 0, i);
		if(i>1)//在教材添加条件，否则死循环
		AdjustDown(heap->D, 0, i-1);//是i-1而非i
	}
}

int main()

{
	double start, finish; /* 定义开始的时间和结束的时间 */
	int m, n = 0;
	printf("请输入待排序数组个数：\n");
	scanf_s("%d", &n);
	List list;
	InIt(&list, n);
	InSert(&list, n);
	FILE *fp;
	fp = fopen("F:\\数据库\\2018-1-4\\数据结构实验四\\test.txt", "w");
	if (!fp)
	{
		printf("file error!\n");
		exit(1);
	}
	/*for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", list.D[i].key);
	}*/
	fclose(fp);
	printf("\n请选择排序方法：\n1、简单选择排序\n2、直接插入排序\n3、冒泡排序\n4、快速排序\n5、两路合并排序\n6、堆排序\n\n");
	scanf_s("%d", &m);
	printf("\n");
	/*if (m!=6)
	{
		printf("原数组：\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", list.D[i].key);
		}
		printf("\n");
	}*/
	
	switch (m)
	{
	case 1:
		printf("\n即将进行简单选择排序！\n\n");
		start = (double)clock();
		SelectSort(&list);
		finish = (double)clock();
		break;
	case 2:
		printf("\n即将进行直接插入排序！\n\n");
		start = (double)clock();
		InsertSort(&list);
		finish = (double)clock();
		break;
	case 3:
		printf("\n即将进行冒泡排序！\n\n");
		start = (double)clock();
		BubbleSort(&list);
		finish = (double)clock();
		break;
	case 4:
		printf("\n即将进行快速排序！\n\n");
		start = (double)clock();
		QuickSort(&list);
		finish = (double)clock();
		break;
	case 5:
		printf("\n即将进行两路合并排序！\n\n");
		start = (double)clock();
		MergeSort(&list);
		finish = (double)clock();
		break;
	case 6:
		MaxHeap heap;
		InIt(&heap, n);
		InSert(&heap, n);
		printf("原数组：\n");
		for (i = 0; i < n; i++)
		{
			printf("%d ", heap.D[i].key);
		}
		printf("\n");
		printf("\n即将进行堆排序！\n\n");
		start = (double)clock();
		HeapSort(&heap);
		finish = (double)clock();
		printf("排序后数组：\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", heap.D[i].key);
		}
		printf("\n");
		break;
	default:
		break;
	}
	/*if (m != 6)
	{
		printf("排序后数组：\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", list.D[i].key);
		}
		printf("\n\n");
	}*/
	printf("排序时间：%.4fms\n", (finish-start));
	

	
	return 0;
}