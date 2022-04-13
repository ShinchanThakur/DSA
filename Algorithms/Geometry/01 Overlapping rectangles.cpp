//FIND IF TWO RECTANGLES OVERLAP

//l -> left upper corner
//r -> right lower corner

int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
    int lx1 = l1[0], lx2 = l2[0], ly1 = l1[1], ly2 = l2[1];
    int rx1 = r1[0], rx2 = r2[0], ry1 = r1[1], ry2 = r2[1];
    
    //Checking if one rectange is a line
    //Because we need to return positive overlap only
    if(lx1 == rx1 or ly1 == ry1 or lx2 == rx2 or ly2 == ry2)
        return false;
    //Checking if one rectangle is left of other
    if(lx1 >= rx2 or lx2 >= rx1)
        return false;
    //Checking if one rectangle is above another
    if(ry1 >= ly2 or ry2 >= ly1)
        return false;
    return true;
}

//Time and space complexity: O(1)
//Problem link: https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/