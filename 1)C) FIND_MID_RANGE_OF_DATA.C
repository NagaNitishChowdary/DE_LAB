// 1)C) WHAT IS MID RANGE OF DATA   
// MID RANGE OF DATA IS THE AVERAGE OF LARGEST AND SMALLEST DATA POINTS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    printf("ENTER NO OF VALUES\n") ;
    int n ;
    scanf("%d" , &n) ;
    printf("enter %d values\n",n) ;
    int i , arr[n] ;
    for(i=0 ; i<n ; i++) scanf("%d",&arr[i]) ;  
    printf("THE MID-RANGE OF DATA IS %d\n",arr[n-1]-arr[0]) ;

    return 0 ;
}
