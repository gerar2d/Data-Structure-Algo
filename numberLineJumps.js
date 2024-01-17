function kangaroo(x1, v1, x2, v2) {
    // Write your code here
    let x = (x2 - x1)/(v1 - v2);
    if (x % 1 == 0 && x > 0) return 'YES';
    return 'NO';      
}