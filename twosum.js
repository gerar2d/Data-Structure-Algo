var twoSum = function(nums, target) {
    let holder = {};
    
    for (let i = 0; i < nums.length; i++){
        console.log(holder)
        let rTarget = target - nums[i];
        if (rTarget in holder){
            return [holder[rTarget], i];
        }
        holder[nums[i]] = i;
    }
};


let a = [3,2,4,5,3,2,10];
let b = 12;
console.log(twoSum(a,b))