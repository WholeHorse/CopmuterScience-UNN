#include <stdio.h>
//Лин. поиск с барьерным элементном
int linbar_search(int p[], unsigned long long size, int find)
{
    int i = 0, temp = p[size - 1];
    p[size - 1] = find;
    while(p[i] != find) i++;
    if(i < (size - 1)) return 1;
    else if(temp == find) return 1;
    else return 0;
    p[size - 1] = temp;
}

void print_array(int A[], unsigned long long int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void shift_left(int p[], unsigned long long size)
{
    int temp = p[0];
    for(int i = 0; i < size; i++){
        if(i == size - 1){
            p[size - 1] = temp;
            break;
        }
        else p[i] = p[i+1];
    }
}

void reverse(int p[], int size)
{
    int A[size];
    for (int i = 0; i < size; i++) {
        A[size - 1 - i] = p[i];
    }
    for (int i = 0; i < size; i++) {
        p[i] = A[i];
    }
}

void shift_right(int p[], unsigned long long size)
{
    int temp = p[size - 1], temp2;
    for(int i = 0; i < size; i++)
    {
        temp2 = p[i+1];
        p[i] = temp2;
    }
    p[0] = temp;
}

int main()
{
    int A[] = {4,5,12,34,56,233,2,5,10};
    print_array(A, sizeof(A)/sizeof(int));
    reverse(A, sizeof(A)/sizeof(int));
    print_array(A, sizeof(A)/sizeof(int));
    return 0;
}



    /*
    int j = -1;
    for(int i = 0; i < size; i++){
        if(p[i] == find){
            j = i;
        }
    }
    return j;
    

    int i = 0;
    while(i < size && p[i] != find) i++;
    return (i == size) ? 0 : 1;
    */
