#include <stdio.h>
#include <stdlib.h>
#define FNAME "input.txt"
int * presuf(char *p,int *A,int n);
int searcher(char *p,int *A,int n);
void main()
{
    char *word;
    int n,x;
    printf("Enter no of letters in the word - ");
    scanf("%d",&n);
    int *A = (int *)malloc(n*sizeof(int));
    word = (char *)malloc((n+1)*sizeof(char));
    printf("Enter the word to search - ");
    scanf("%s",word);
    A = presuf(word,A,n);
    x = searcher(word,A,n);
    printf("The no of occurrences of the %s is %d \n",word,x);
}
int * presuf(char *p,int *A,int n)
{
    int k=-1,q;
    A[0] = -1;
    for(q=1;q<n;q++)
    {
        while((k>-1)&&(p[k+1]!=p[q]))
            k = A[k];
        if(p[k+1]==p[q])
            k++;
        A[q] = k;
    }
    return A;
}
int searcher(char *p,int *A,int n)
{
    int q = -1,i,m,x=0;
    FILE * fp = fopen(FNAME,"r");
    fseek(fp,0,SEEK_END);
    m = ftell(fp);
    printf("\nThe total no of letters in the string - %d\nThe string is -\n",m);
    rewind(fp);
    char *T = (char *)malloc((m+1)*sizeof(char));
    fscanf(fp,"%s",T);
    printf("\n%s\n",T);
    for(i=0;i<m;i++)
    {
        while((q>-1)&&(p[q+1]!=T[i]))
            q = A[q];
        if(p[q+1]==T[i])
            q++;
        if(q==n-1)//If you want the shift values modify
            x++;//this statement by creating an array
    }
    return x;
}
