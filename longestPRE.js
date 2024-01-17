var longestCommonPrefix = function(strs) {
    if (!strs.length) return '';
    let holder = '';
    for (let i = 0; i < strs[0].length; i++){
        let first = strs[0][i];
        if (!first)  return '';
        if (strs.every(str => str[i] === first)){
            holder += first;
        } else break;
    }

    return holder;
};


let a = ["flower","flow","flight"];

console.log(longestCommonPrefix(a));