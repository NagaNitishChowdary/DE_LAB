// 4)A) IMPLEMENT MIN-MAX NORMALIZATION
// DEF ==> PERFORMS A LINEAR TRANSFORMATION ON THE ORIGINAL DATA.
// THIS TECHNIQUE GETS ALL THE SCALED DATA FROM THE RANGE (0,1) 

// FORMUALA == >
// scaled data = (x-xmin)/(xmax-xmin)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n ;
    printf("ENTER N VALUE \n",n) ;
    scanf("%d",&n) ;
    float arr[n] ;
    for(int i=0 ; i<n ; i++) scanf("%f",&arr[i]) ;

    int mini = arr[0] , maxi = arr[n-1] ;
    for(int i=0 ; i<n ; i++){
        if(mini > arr[i]) mini = arr[i] ;
        if(maxi < arr[i]) maxi = arr[i] ;
    }

    for(int i=0 ; i<n ; i++){ arr[i] = (arr[i]-mini)/(maxi-mini) ; 
    printf("%.2f ",arr[i]) ; }

    return 0 ;
}
