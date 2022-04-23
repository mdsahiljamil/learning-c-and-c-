#include <stdio.h>
#include <stdlib.h>

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter value at %d : ", arr[i]);
        scanf("%d", arr[i]);
    }
}
void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("\nElemnt at %d is %d ", i, arr[i]);
}

void insert(int *a, int index,int data,int *size)
{
    int l = *size;
    int i;
    for ( i = index; i < l - 1; i++)
    {
        a[i+1] = a[i];
    }
    a[i] = data;
    *size = l + 1;
}




void delete (int *a, int index,int *size)
{
    int l = *size;
    for (int i = index; i <  l - 1; i++)
    {
        a[i] = a[i + 1];
    }
    *size = l - 1;
}



void bubble_sort(int *arr, int n)
{
    printf("\nBubble");
    int t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < ((n - 1) - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}



void selection_sort(int *arr, int n)
{
    printf("\nselction");
    int t, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
}




void insertion_sort(int *arr, int n)
{
    // int n[]={-999,2,1,11,4,10,3,5};
    printf("\ninsertion");
    int t;
    int j;
    for (int i = 1; i <= n; i++)
    {
        t = arr[i];
        j = i - 1;
        while (t < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = t;
    }
}





int partition_quick_sort(int arr[], int low, int high)
{
    int i = low + 1;
    int j = high;
    int temp;
    int pivot = arr[low];

    while (i - 1 < j) // -1 bcz so tht the loop can run 1 extra time
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}
void quick_sort(int *arr, int low, int high)
{
    int partition_index;
    if (low < high)
    {
        partition_index = partition_quick_sort(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

void linear_search(int *a, int elemnt)
{

    int c = 0;
    for (int i = 0; i < 7; i++)
    {
        if (elemnt == a[i])
        {
            printf("\nIs present at %d ", i);
            c = 1;
        }
    }
    if (c == 0)
        printf("Elemnt not present\n");
}

void binary_search(int *a, int elemnt)
{

    int u = 0;
    int l = 7;
    int count = 0;
    while (u <= l)
    {
        int mid = (u + l) / 2;
        if (a[mid] == elemnt)
        {
            count = 1;
            break;
        }
        if (a[mid] > elemnt)
            l = mid;
        if (a[mid] < elemnt)
            u = mid;
    }
    if (count == 1)
        printf("Yes the elmnt is present");
    if (count == 0)
        printf("Nopes the elmnt isn't present");
}

void PUSH(int *arr, int *top, int *size, int p)
{
    int t = *top;
    int s = *size;
    if (t + 1 >= s) // or( top>=size-1)
        printf("Stackover flow\n");
    else
    {
        *top = t + 1;
        t = *top;
        arr[t] = p;
    }
    printf("\n");
}
int POP(int *arr, int *top)
{
    int t = *top;
    if (t == -1)
        return -1;
    else
    {
        *top = t - 1;
        t = *top;
        return arr[t];
    }
}
void display(int *arr, int *top)
{
    int t = *top;
    if (t == -1)
        printf("No elements\n");
    else
    {
        for (int i = t; i >= 0; i--)
            printf("%d\n", arr[i]);
    }
}





void main(void)
{
    printf("1. Insert \n");
    printf("2. Delete  \n");
    printf("3. search \n");
    printf("4. Sorting \n");
    printf("5. Stack \n");
    printf("6. Exit \n");
    while (1)
    {
        int arr[7+5];
        int size=(int)sizeof(arr)/sizeof(arr[0])-5;
        
        printf("Enter the choice : ");
        int c1;
        scanf("%d", &c1);
        switch (c1)
        {
        case 1:
        {
            int i,data;
            input(arr, size);
            printf("Enter the index to be insereted : ");
            scanf("%d", &i);
            printf("Enter the data to be insereted : ");
            scanf("%d", &data);
            insert (arr, i,data, &size);
            show(arr, size);
            break;
        }
        case 2:
        {
            int d;
            input(arr, size);
            printf("Enter the index to be deleted : ");
            scanf("%d", &d);
            delete (arr, d,&size);
            show(arr,size);
            break;
        }
        case 4:
        {
            printf("1. Selection \n");
            printf("2. Bubble  \n");
            printf("3. Insertion \n");
            printf("4. QuickSort \n");
            printf("5. MergeSort \n");
            printf("6. Exit \n");
            printf("Enter the choice : ");
            int c;
            scanf("%d", &c);
            switch (c)
            {
            case 1:
            {
                input(arr, size);
                selection_sort(arr,size);
                show(arr, size);
                break;
             }
            case 2:
            {
                input(arr, size);
                bubble_sort(arr, size);
                show(arr, size);
                break;
            }
            case 3:
            {
                arr[0] = -999;
                size = size + 1;
                input(arr, size);
                bubble_sort(arr, size);
                show(arr, size);
                break;
            }
            case 4:
            {
                input(arr, size);
                quick_sort(arr, 0,size-1);
                show(arr, size);
                break;
            }
            case 5:
            {
                #include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}
            }
            case 6:
            {
                printf("BYE BYE !! ");
            }
            default:
                printf("Enter again Wrong Choice ");
            }
        }
        case 3:
        {
            printf("1. Linear Search \n");
            printf("2. Binary Search \n");
            int c;
            printf("Enter the choice :\n");
            scanf("%d", &c);
            switch(c)
            {
                case 1:
                {
                    input(arr,size);
                    int n;
                    printf("Enter the number to be  searched \n");
                    scanf("%d", &n);
                     linear_search(arr, n);
                     break;
                }
                case 2:
                {
                    input(arr, size);
                    int n;
                    printf("Enter the number to be  searched \n");
                    scanf("%d", &n);
                    binary_search(arr, n);
                    break;
                }
                default:
                {
                    printf("WWrong Choice !! \n");
                }
            }
        }
        case 5:
        {
            int size, top;
            top = -1;
            size = 5;
            int n[size];

            printf("1.PUSH  Elements\n");
            printf("2.POP Elements\n");
            printf("3.Display\n");
            printf("4.Exit \n");
            while (1)
            {
                printf("CHOOSE ");
                int c;
                scanf("%d", &c);
                if (c == 1)
                {
                    int p;
                    printf("PUSH in");
                    scanf("%d", &p);
                    PUSH(n, &top, &size, p);
                }
                if (c == 2)
                {
                    printf("%d  POPed \n", POP(n, &top));
                }
                if (c == 3)
                {
                    display(n, &top);
                }
                if (c == 4)
                {
                    printf("Good Bye\n");
                    break;
                }
            }   //break;
        
        }
        case 6:
        {
            printf("EXITING  Bye !!");
            exit(0);
        }
        default:
        {
            printf("Wrong  choice , Enter again pls !!! \n\n");
        }
        }
    }
}