//MISSING AND REPEATING NUMBER

//We will use the XOR method as it overcomes the problem of overflow which can occur while using maths method (product and sum)

int findXXorY(vector<int> &arr, int arr_size){
	int xXorY = arr[0];
	for(int i=1; i<arr_size; i++)
		xXorY ^= arr[i];
	for(int i=1; i<=arr_size ; i++)
		xXorY ^= i;
	return xXorY;
}

int findNumberWithSameRightmostSetBitAndOtherBitsZero(int n){
	return n & ~(n-1);
}

void divideIntoBuckets(int &num1, int &num2, int numberWithSameRightmostSetBitAsXXorY, vector<int> &arr, int arr_size){
	for(int i=0; i<arr_size; i++){
		if(arr[i] & numberWithSameRightmostSetBitAsXXorY)
			num1 ^= arr[i];
		else
			num2 ^= arr[i];
	}
	for(int i=1; i<=arr_size; i++){
		if(i & numberWithSameRightmostSetBitAsXXorY)
			num1 ^= i;
		else
			num2 ^= i;
	}
}

int getMissingNumber(int num1, int num2, vector<int> &arr, int arr_size){
	int countNum1 = 0;
	for(int i=0; i<arr_size; i++)
		if(arr[i] == num1)
			countNum1++;
	if(countNum1 == 0)
		return num1;
	else
		return num2;
}

int getRepeatedNumber(int num1, int num2, int missingNumber){
	if(missingNumber == num1)
		return num2;
	else
		return num1;
}

vector<int> repeatedAndMissingNumber(vector<int> &arr) {
	int arr_size = arr.size();
	int xXorY = findXXorY(arr, arr_size);
	int numberWithSameRightmostSetBitAsXXorY = findNumberWithSameRightmostSetBitAndOtherBitsZero(xXorY);
	int num1 = 0, num2 = 0;
	divideIntoBuckets(num1, num2, numberWithSameRightmostSetBitAsXXorY, arr, arr_size);
	int missingNumber = getMissingNumber(num1, num2, arr, arr_size);
	int repeatedNumber = getRepeatedNumber(num1, num2, missingNumber);
	return {repeatedNumber, missingNumber};
}

//Time Complexity: O(n)
//Space Complexity: O(1)

// Problem Link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/