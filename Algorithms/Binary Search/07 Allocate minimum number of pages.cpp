//ALLOCATE MINIMUM NUMBER OF PAGES

//Allocate books to students so that the maximum number of pages allocated to a student is minimum

bool isAllocationPossible(int pages[], int n, int totalStudents, int maxPagesPerStudent){
    int studentCount = 1, pagesAllocated = 0;
    for(int i=0; i<n; i++){
        if(pagesAllocated + pages[i] > maxPagesPerStudent){
            studentCount++;
            pagesAllocated = pages[i];
            if(pagesAllocated > maxPagesPerStudent)
                return false;
        }
        else
            pagesAllocated += pages[i];
    }

    return studentCount <= totalStudents;
}

int findPages(int pages[], int n, int totalStudents) 
{
    if(totalStudents > n)
        return -1;
    int low = pages[0], high = 0, mid, maxPagesPerStudent;
    for(int i=0; i<n; i++)
        low = min(low, pages[i]),       high += pages[i];

    while(low <= high){
        mid = low + (high - low)/2;
        maxPagesPerStudent = mid;
        if(isAllocationPossible(pages, n, totalStudents, maxPagesPerStudent))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

//Time complexity: (n * log(sp))    -> sp = sum of pages
//Space complexity: O(1)

//Problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/