let s = '12:01:00PM'


if (s.includes("P") && s.slice(0,2) === "12"){
    return `${s.slice(0,8)}`;
}
else if (s.includes("P")){
    return `${(s.slice(0,2)+12).toString()}${s.slice(2,8)}`;
}
else if (s.includes("A") && s.slice(0,2) === "12"){
    return `00${s.slice(2,8)}`;}
else{
        return `${s.slice(0,8)}`;
    }


    


console.log(s.slice(0,8))


// function timeConversion(s) {
//     // Write your code here
//   if (s.includes("P") && s.slice(0, 2) === "12") {
//     return `${s.slice(0, 8)}`;
//   } else if (s.includes("P")) {
//     return `${(+s.slice(0, 2) + 12).toString()}${s.slice(2, 8)}`;
//   } else if (s.includes("A") && s.slice(0, 2) === "12") {
//     return `00${s.slice(2, 8)}`;
//   } else {
//     return s.slice(0, 8);
//   }
// }