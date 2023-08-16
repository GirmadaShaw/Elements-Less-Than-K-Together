/*
Given an array of n positive integers and a number k. 
Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
Input array= {1, 5, 4, 7, 2, 10} and k = 6 
Output : 1
Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
Output: 2
*/

#include <iostream>

int min( int a, int b )
{
    if( a>b)
        return a ;
    else 
        return b ; 
}

int main()
{
    //int arr[] = {1, 5, 4, 7, 2, 10} , k=6 ;
    int arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5 ;
    //int arr[] = {5, 4, 6, 10, 35, 30, 8} , k = 9 ;
    //int arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5 ;
    int size = sizeof(arr) / sizeof(int) ;

//Time Complexity: O(n) , Space Complexity: O(1)

    int count_good_values=0, count_bad_values=0 ;

    for ( int i=0 ; i<size ; i++ )
        if ( arr[i] <= k)
        count_good_values ++ ;
    for( int i=0 ; i<count_good_values ; i++ )
        if( arr[i] > k)
        count_bad_values ++ ;  

    int count_swaps = count_bad_values ; 
    for ( int i=0 , j=count_good_values ; j<size ; i++ , j++ )
    {
        if (arr[i] > k) 
            count_bad_values -- ;
        if( arr[j] > k  )
            count_bad_values ++ ;
        
        count_swaps = min( count_bad_values , count_swaps );
    }


 std::cout << count_swaps ; 

    
}