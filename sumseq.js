let sum = function(a,b,c){
    let p = 0;
    if (b >= 0){
        for (let i = a; i <= b; i++){
            p += i;
    }}
    else if (b < 0){
        for (let i = a; i >= b; i--){
            p += i;
        }
    }
    if (p === c)return p;
    else if (c >= 0){
        for (let i = p; i <= c; i++){
            p += i;
    }}
    else if (c< 0){
        for (let i = p; i >= c; i--){
            p += i;
        }
    }




    // for (let f = b; f <= c; f++){
    //     p += f;
    // }
    return p;
}

a = 2;
b = 2;
c = -3;

console.log(sum(a,b,c));