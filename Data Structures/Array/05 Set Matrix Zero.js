var setZeroes = function(matrix) {
    let makeAllZeroInRow1 = false;
    const m = matrix[0].length;
    const n = matrix.length;
    for(let i=0, j=0; j<m; j++)
        if(matrix[i][j] === 0){
            makeAllZeroInRow1 = true;
            break;
        }
    for(let i=1; i<n; i++)
        for(let j=0; j<m; j++)
            if(matrix[i][j] === 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
    for(let i=n-1; i>0; i--)
        for(let j=m-1; j>=0; j--)
            if(matrix[i][0] === 0 || matrix[0][j] === 0)
                matrix[i][j] = 0;
    if(makeAllZeroInRow1 === true)
        for(let i=0, j=0; j<m; j++)
            matrix[i][j] = 0;
};
