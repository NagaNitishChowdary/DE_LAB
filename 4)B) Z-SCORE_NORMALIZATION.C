// 4)A) IMPLEMENT Z-SCORE NORMALIZATION
// DEF ==> THIS TECHNIQUE IS USED TO STANDARDIZE THE FEATURES OF A 
// DATASET BY SUBTRACTING THE MEAN AND DIVIDING BY THE STANDARD DEVIATION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n ;
    printf("ENTER N VALUE \n",n) ;
    scanf("%d",&n) ;
    float arr[n] ;
    for(int i=0 ; i<n ; i++) scanf("%f",&arr[i]) ;

    float mean = 0 , sd = 0 ;
    for(int i=0 ; i<n ; i++) mean += arr[i] ;
    mean /= n ;
    for(int i=0 ; i<n ; i++) sd += ((arr[i]-mean)*(arr[i]-mean)) ;
    sd = sqrt(sd/n) ;

    // APPLY Z-SCORE NORMALIZATION
    for(int i=0 ; i<n ; i++){ arr[i] = (arr[i]-mean)/sd ;
    printf("%.2f ",arr[i]) ; }

    return 0 ;
}
