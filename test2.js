let a = ['(',')','{','}'];
let holder = [];
let b = [];
let c = [];
let j = 0;
for (let x = 0; x <= a.length; x++){
    if (x < a.length/2){
        holder.push(a);
    }else{
        b[j++] = a.pop();
    }
}

console.log(b.indexOf('{'));
console.log(holder);
console.log(b.sort());