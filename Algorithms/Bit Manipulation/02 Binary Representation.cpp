//REPRESENT INTEGER IN BINARY FORMAT

//ITERATIVE
string getBinaryRep(int n)
{
	string binaryRep = "0";
    for(long i = 1 << 30; i > 0; i /= 2){
    	if(n & i)
    		binaryRep += "1";
    	else
    		binaryRep += "0";
    }
    return binaryRep;
}

//RECURSIVE
string binRec(int n){
	string s = "";
    if(n > 1)
    	s = getBinaryRep(n/2);
    if(n%2)
    	s += "1";
    else
    	s += "0";
    return s;
}

string getBinaryRep(int n)
{
	string s = "";
    s = binRec(n);
    while(s.length() < 30)
    	s = "0" + s;
    return s;
}

//USING BITSET (STL)
string getBinaryRep(int n)
{
	string s = "";
	//we can choose any number of bit representation
    bitset<8> b(n);
    for(int i = 7; i >= 0; i--)
    	if(b[i])	s += "1";
    	else	s += "0";
    return s;
}

//Time and space complexity: O(1)
//Problem link: https://practice.geeksforgeeks.org/problems/binary-representation5003/1/


//For more details, read from here - https://www.geeksforgeeks.org/c-bitset-and-its-application/