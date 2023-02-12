// 1A) FIND MEAN , MEDIAN OF DATA

#include<stdio.h>

int main(){
    printf("ENTER NO OF VALUES\n") ;
    int n ;
    scanf("%d" , &n) ;
    printf("enter %d values\n",n) ;
    int i , arr[n] ;
    double mean = 0 ;
    for(i=0 ; i<n ; i++){ scanf("%d",&arr[i]) ;  mean += arr[i] ; }
    mean /= n ;
    printf("MEAN IS %f\n" , mean) ;
    // for(int i=0 ; i<n ; i++) printf("%d ",arr[i]) ;
    if(n&1) printf("MEDIAN IS %d\n" , arr[n/2]) ;
    else printf("MEDIAN IS %d\n" , (arr[n/2]+arr[n/2+1])/2) ;
    return 0 ;
}
