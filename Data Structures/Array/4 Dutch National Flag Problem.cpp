//DUTCH NATIONAL FLAG PROBLEM

//Segregate 0s and 1s in an array

void segregate0and1(int arr[], int arr_size) {
    int left = 0, right = arr_size-1;
    while(left<right){
        while(arr[left]==0 and left<right)
            left++;
        while(arr[right]==1 and left<right)
            right--;
        if(left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

//Time Complexity: O(n)
//Space Complexity: O(1)

//*************************************************************************************************

//Segregate 0s, 1s and 2s in an array

void sort012(int arr[], int arr_size) {
    int zero = 0, pointer = 0, two = arr_size-1;
    while(pointer<=two){
        switch(arr[pointer]){
            case 0: swap(arr[zero++], arr[pointer++]);
                    break;
            case 1: pointer++;
                    break;
            case 2: swap(arr[pointer], arr[two--]);
        }
    }
}

//Time Complexity: O(n)
//Space Complexity: O(1)