#include<iostream>
#include<math.h>
using namespace std;
const int n=8;	

class point{
	public:
		int x,y;
};
	float dist(point a, point b)  {	
		float distance=sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );		
		return distance;
	}
	void printarray(point arr[]){ 
	for(int i=0;i<n;i++)
		cout<<"  ("<<arr[i].x<<","<<arr[i].y<<")  ";
	cout<<endl;	
	}

template<class T>
void swap(T *a,T *b){
	T temp=*a;
	*a=*b;
	*b=temp;
}

void SortByX(point arr[n]){
	int i, j, min_idx;  
    for (i = 0; i < n-1; i++)  
    {   
        min_idx = i;  
        for (j = i+1; j < n; j++)  
	        if (arr[j].x < arr[min_idx].x)  
	            min_idx = j;  
        swap(arr[min_idx], arr[i]);   
    }	
}
float Find_Min_Intersaction_Dist(point arr[], int start, int end, float Y_limit)
{
	int Index_array[end-start+1];
	for(int i=start,index=0;i<=end;i++,index++)
		Index_array[index]=i;

	int i, j, min_idx;  
    for (i = 0; i < end-start; i++)  
    {   
        min_idx = i;  
        for (j = i+1; j <= end-start; j++)  
	        if (arr[Index_array[j]].y < arr[Index_array[min_idx]].y)  
	            min_idx = j;  
        swap(Index_array[min_idx], Index_array[i]);   
    }
    
    for(i=0;i<end-start;i++)
    {
    	for(j=i+1;j<=end-start;j++)
    	{
    		if(arr[Index_array[j]].y - arr[Index_array[i]].y >= Y_limit)
    			break;
    		if( dist( arr[Index_array[i]] , arr[Index_array[j]] ) < Y_limit)
    			Y_limit = dist( arr[Index_array[i]] , arr[Index_array[j]] );
		}	
	}
	
	return Y_limit;
}

float RecursiveFun(point arr[],int start,int end)
{
	float ans;
	cout<<"\nfunction call with value   start = "<<start<<" & end = "<<end;
	if(end-start==0)
	{   start=start-1;
		ans = dist(arr[start],arr[end]) ;
		return ans;
	}
	if(end-start==1)
	{		ans = dist(arr[start],arr[end]) ;
			return ans;	}
	else
	{
		int mid=(start+end)/2;
		float LeftMinDist=RecursiveFun(arr,start,mid);
		float RightMinDist=RecursiveFun(arr,mid+1,end);
		
		cout<<"\n\nleft half min dist  =  "<<LeftMinDist<<"   ||  right half min dist = "<<RightMinDist;
		
		float mindist = (LeftMinDist < RightMinDist) ? LeftMinDist : RightMinDist;
		float midline= ( arr[mid].x + arr[mid+1].x )/2;	
		
		float NewLeftValue = (midline-mindist) > arr[start].x ? midline-mindist : arr[start].x; 
		float NewRightValue = (midline+mindist) < arr[end].x ? midline+mindist : arr[end].x; 
		int NewLeftIndex,NewRightIndex;
		for(int i=start;i<=end;i++)
		{	if(arr[i].x >= NewLeftValue)
				{	NewLeftIndex=i;
					break;		}
		}
		for(int i=NewLeftIndex;i<=end;i++)
		{	if(arr[i].x >= NewRightValue)
				{	NewRightIndex=i-1;
					break;		}
		}
		
		ans = Find_Min_Intersaction_Dist(arr,NewLeftIndex,NewRightIndex,mindist);
		cout<<"   ||  returning final min value : "<<ans<<endl;
		return ans;
	}	
}

int main()
{
	
	point arr[] = { {1,1}, {5,5}, {3,3},    {9,4}, {11,5},      {14,6}, {16,8}, {19,2} };	
	
	cout<<"============ starting points  ===============\n";
	printarray(arr);
	SortByX(arr);
	cout<<"========== after sorting by X co-ordinates ===========\n";
	printarray(arr);
														
	float MinimumDistance = RecursiveFun(arr,0,n-1);
	cout<<"\n Minimum Distance is  :  "<<MinimumDistance;	
	return 0;
}

