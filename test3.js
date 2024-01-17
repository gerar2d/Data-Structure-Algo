var minimizeTheDifference = function (m, t) {
    let h = new Set([0]);

    for (let row of m){
        let set = new Set();
        for (value of row){
            for (sum of h){
                set.add(value + sum)
            }
        }
        h = set;
    }
    let min = Infinity;
    for (let s of h){
        min = Math.min(min, Math.abs(t-s))
    }
    return min
  }

  mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
  for (let val of mat){
   // console.log(val)
  }
  console.log(minimizeTheDifference(mat,target));