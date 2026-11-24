/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    var cnt=0;
    for(s in args){
        cnt++;
    }
    return cnt;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */