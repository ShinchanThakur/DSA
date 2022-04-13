//NUMBER WITH SAME RIGHTMOST SET BIT

int numberWithSameRightmostSetBit(int n){
	return n & ~(n-1);
	return n & -n;				//-n -> 2's compliment -> Rightmost set bit same, all others inverted
	return 
}

//POSITION OF RIGHTMOST SET BIT

// I/P    18,   Binary Representation 010010
// O/P   2
// I/P    19,   Binary Representation 010011
// O/P   1

int positionOfRightMostSetBit(int n){
	return ffs(n);		//-> library function
	return log2(numberWithSameRightmostSetBit(n)) + 1;
}

int positionOfRightMostSetBit(int n)
{
    if(n == 0)
        return 0;
    int m = 1, position = 1;
    while(!(n & m)){
        m = m << 1;
        position++;
    }
    return position;
}

int positionOfRightMostSetBit(int n)
    {
        int position = 1;
        while(n > 0){
            if(n & 1)
                return position;
            n = n >> 1;
            position++;
        }
        return 0;
    }

//Time complexity: O(log2n) -> O(32) -> O(1)
//Space complexity: O(1)

//Problem link: https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1/