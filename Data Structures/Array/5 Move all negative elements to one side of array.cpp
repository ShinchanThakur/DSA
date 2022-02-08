//MOVE ALL NEGATIVE ELEMENTS TO ONE SIDE OF ARRAY

//ORDER IS NOT MAINTAINED
//It can be done by two pointers
//Here we will do it by Dutch National Flag Problem approach

void moveNegativeToOneSideOfArray(int arr[], int arr_size){
	int pointer = 0;
	int positive = arr_size-1;
	while(pointer <= positive){
		if(arr[pointer] < 0)
			pointer++;
		else
			swap(arr[pointer], arr[positive--]);
	}
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//*************************************************************************************************

//ORDER IS MAINTAINED

//Continue from here: https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/
//After 15 Feb: https://drive.google.com/file/d/1FMdN_OCfOI0iAeDlqswCiC2DZzD4nPsb/view