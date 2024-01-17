let a = [1,2,];
let b = 322;
let c = [1,2,3,4]
let l = 0;
let v = b.toString();
let x = [];
let t = v.split("").reverse().join("");

let k = ["flower","flow","flight"];

let j = "IV";
for (let i = 0; i< a.length/2; i++){
    x.push(a.pop())
}



function birthday(s, d, m) {
    let validDivisions = 0;
    
    for(let i = 0; i < 1 + s.length - m; i++){
        const newS = [...s]
        console.log(newS);
        if(newS.splice(i, m).reduce((squareSum, square) => squareSum + square) === d){
            validDivisions++
        }
    }
    return validDivisions
}

var romanToInt = function(s) {
    let count = 0;
    let trash = [];
    while (!s == 0){
        if (s.includes("IV")){
            count + 4;
            trash.push(s.pop("IV"));
        }
        if (s.includes("IX")){

        }
    }
    
};

a.push(4)
a.push(5)
console.log(a)

