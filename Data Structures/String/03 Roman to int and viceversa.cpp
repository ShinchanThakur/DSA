//ROMAN TO INT

void getMap(map<char, int> &m){
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
}

int romanToInt(string s) {
    map<char, int> m;
    getMap(m);
    int resInt = 0;
    for(int i=0; i<s.length(); i++){
        if(i < s.length() - 1 and m[s[i]] < m[s[i + 1]]){
            resInt += m[s[i+1]] - m[s[i]];
            i++;
        }
        else
            resInt += m[s[i]]; 
    }
    return resInt;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/roman-to-integer/

/******************************************************************************************************/

//INT TO ROMAN

string intToRoman(int number) {
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i = 12;
    string roman = "";
    while(number){
        while(number >= num[i]){
            roman += sym[i];
            number -= num[i];
        }
        i--;
    }
    return roman;
}

//Time complexity: O(n)
//Space complexity: O(1)

//Problem link: https://leetcode.com/problems/integer-to-roman/