
var minMeetingRooms = function(intervals) {
    if (intervals == null) return 0;

    intervals.sort(((a,b) => a[0]-b[0]))

    let queue = [];
    queue.push(intervals[0][1]);

    for (let i = 1; i < intervals.length; i++){
        console.log(queue);
        if (intervals[i][0] >= queue[0]){
            queue.shift();
        }
        queue.push(intervals[i][1]);
        queue.sort(((a,b) => a-b))
    }

    return queue.length;
};


a = [[0,30],[5,10],[15,20]];

console.log(minMeetingRooms(a));