//IMPLEMENT POW(x,n) USING BINARY EXPONENTIATION

double myPow(double x, int n){
	int exponent = abs(n);
	double result = 1;
	while(exponent){
		if(exponent%2){
			result *= x;
			exponent--;
		}
		else{
			x *= x;
			exponent /= 2;
		}
	}
	if(n < 0)
		result = 1/ result;
	return result;
}

//Time Complexity: O(log(n))
//Space Complexity: O(1)

//Problem Link: https://leetcode.com/problems/powx-n/