/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const x = 0;
    for (let i = 0; i < prices.length; i++){
        if (x < 0){
            return 0;
        }
        else{
            for (let y = 1; y < prices.length; y++){
                if (prices[y]-prices[x] > x){
                    x = prices[y]-prices[x];
                }
            }
        }
    }
    return x;
};



let prices = [7,1,5,3,6,4];
console.log(reversed(prices));

