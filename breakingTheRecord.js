let a = [10,5,20,20,4,5,2,25,1];

function breakingRecords(scores) {
    let res =[0,0];
    let ss=[scores[0]];
    for(let x of scores){
        if(x>Math.max(...ss)) res[0]++;
        if(x<Math.min(...ss)) res[1]++;
        console.log(ss);
        ss.push(x)
    }
    return res;
  }

  console.log(breakingRecords(a));