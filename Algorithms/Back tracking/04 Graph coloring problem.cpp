//GRAPH COLORING PROBLEM
//Colour n nodes of a graph in atmost m colors such that no two adjacent nodes have same color

bool isSafe(int node, int color, bool graph[101][101], int colorArray[], int totalNodes){
    for(int i=0; i<totalNodes; i++){
        if(i != node and graph[node][i] and colorArray[i] == color)   return false;
    }
    return true;
}

bool colorGraph(bool graph[101][101], int totalColors, int totalNodes, int node, int colorArray[]){
    if(node == totalNodes)   return true;

    for(int color = 1; color <= totalColors; color++){
        if(isSafe(node, color, graph, colorArray, totalNodes)){
            colorArray[node] = color;
            if(colorGraph(graph, totalColors, totalNodes, node + 1, colorArray))    return true;
            colorArray[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int totalColors, int totalNodes)
{
    int node = 0, colorArray[totalNodes] = {0};
    colorGraph(graph, totalColors, totalNodes, node, colorArray);
}

//Time complexity: O(m^n)   -> n = number of node, m = number of colors
//Space complexity: O(n)

//Problem link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#