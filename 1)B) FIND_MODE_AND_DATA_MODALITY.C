// 1B) FIND MODE AND DATA MODALITY
// DATA MODALITY MEANS NUMBER OF MODES 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int a,int b){
    return (a>b)? a : b ;
}

int main(){
    printf("ENTER NO OF VALUES\n") ;
    int n ;
    scanf("%d" , &n) ;
    printf("enter %d values\n",n) ;
    int i , arr[n] ;
    for(i=0 ; i<n ; i++) scanf("%d",&arr[i]) ;  
    
    int maxi = -1e9 , cnt = 0 , ele = arr[0] , arr1[n] ;
    for(int i=0 ; i<n ; i++){
        if(arr[i] == ele) cnt++ ;
        else{
            cnt = 1 ;
            ele = arr[i] ;
        }
        maxi = max(maxi,cnt) ;
        arr1[i] = cnt ;
    }

    int arr2[n] , k = 0 ;
    for(int i=0 ; i<n ; i++){
        if(arr1[i] == maxi) arr2[k++] = arr[i] ; 
    }

    printf("THE MODE OF THE DATA IS ") ;
    for(int i=0 ; i<k ; i++) printf("%d ",arr2[i]) ;
    printf("\n") ;

    printf("THE DATA MODALITY IS %d\n",k) ;

    return 0 ;
}
