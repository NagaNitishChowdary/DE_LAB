#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct point{
	char val ;
	double x,y ;
	double dist ;
};

int cmp(const void* p,const void* q){
	if(((struct point*)p)->dist < ((struct point*)q)->dist)
		return 0 ;
	return 1 ;
}

char classifyPoint(struct point arr[],int n,int k,struct point knnc){
	for(int i=0 ; i<n ; i++){
		arr[i].dist = sqrt((arr[i].x-knnc.x)*(arr[i].x-knnc.x))+((arr[i].y-knnc.y)*(arr[i].y-knnc.y)) ;
	}
	qsort(arr,n,sizeof(struct point),cmp) ;
	int cnt1 = 0 , cnt2 = 0 ;
	for(int i=0 ; i<k ; i++){
		if(arr[i].val == 'M') cnt1++ ;
		else if(arr[i].val == 'L') cnt2++ ;
	}
	return cnt1>cnt2 ? 'M' : 'L' ;
}

int main(){
	int n = 18 ;
	struct point arr[n] ;

	arr[0].x = 158 ;
	arr[0].y = 58 ;
	arr[0].val = 'M' ;

    arr[1].x = 158;
    arr[1].y = 59;
    arr[1].val = 'M';
  
    arr[2].x = 158;
    arr[2].y = 63;
    arr[2].val = 'M';
  
    arr[3].x = 160;
    arr[3].y = 59;
    arr[3].val = 'M';
  
    arr[4].x = 160;
    arr[4].y = 60;
    arr[4].val = 'M';
  
    arr[5].x = 163;
    arr[5].y = 60;
    arr[5].val = 'M';
  
    arr[6].x = 163;
    arr[6].y = 61;
    arr[6].val = 'M';
  
    arr[7].x = 160;
    arr[7].y = 64;
    arr[7].val = 'L';
  
    arr[8].x = 163;
    arr[8].y = 64;
    arr[8].val = 'L';
  
    arr[9].x = 165;
    arr[9].y = 61;
    arr[9].val = 'L';
  
    arr[10].x = 165;
    arr[10].y = 62;
    arr[10].val = 'L';
  
    arr[11].x = 165;
    arr[11].y = 65;
    arr[11].val = 'L';
  
    arr[12].x = 168;
    arr[12].y = 62;
    arr[12].val = 'L';
  
    arr[13].x = 168;
    arr[13].y = 63;
    arr[13].val = 'L';
  
    arr[14].x = 168;
    arr[14].y = 66;
    arr[14].val = 'L';
  
    arr[15].x = 170;
    arr[15].y = 63;
    arr[15].val = 'L';
  
    arr[16].x = 170;
    arr[16].y = 64;
    arr[16].val = 'L';

    arr[17].x = 170;
    arr[17].y = 68;
    arr[17].val = 'L';

    struct point knnc ;
    knnc.x = 161 ;
    knnc.y = 61 ;

    // K CAN BE TAKEN ANY VALUE
    // JUST IT IS CHECKING NEAREST K VALUE DISTANCES
    int k = 3 ;  
    printf("THE UNKNOWN DATA POINT FALLS UNDER THE GROUP OF %c\n",classifyPoint(arr,n,k,knnc)) ;

	return 0 ;
}
