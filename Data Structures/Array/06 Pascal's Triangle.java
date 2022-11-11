class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalsTriangle = new ArrayList<List<Integer>>();
        for(int i=1; i<=numRows; i++){
            List<Integer> row = new ArrayList<Integer>(i);
            row.add(1);
            for(int j=1; j<i-1; j++){
                row.add(pascalsTriangle.get(i-2).get(j-1) + pascalsTriangle.get(i-2).get(j));
            }
            if(i != 1)   row.add(1);
            pascalsTriangle.add(row);
        }
        return pascalsTriangle;
    }
}
