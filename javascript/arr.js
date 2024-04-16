let arr=[1,2,3];
arr.splice(3,3,7,8,9);
console.log(arr)

//合并两个十万级别数量的数组-》使用扩展运算符
// const array1 = new Array(100000).fill(null).map((_, i) => i); // 填充十万个数字
// const array2 = new Array(100000).fill(null).map((_, i) => i + 100000); // 填充另外十万个数字
//
// const mergedArray = [...array1, ...array2]; // 使用扩展运算符合并数组
// console.log(mergedArray)

// const array1=[1,2,3,4,2];
// const array2=[5,6,7,9];
// const mergedArray=[array1,array2];//[ [ 1, 2, 3, 4, 2 ], [ 5, 6, 7, 9 ] ]
// const mergedArrayWithOperatorExtend=[...array1,...array2];//[1, 2, 3, 4, 2, 5, 6, 7, 9]
//
// console.log(mergedArrayWithOperatorExtend)

//去重
const repeat=[1,2,2,3,3,4,6,7]

//使用set
const uniqueArray=[...new Set(repeat)]
console.log(uniqueArray)

//使用filter：
const filterArray=repeat.filter((item,index,arr)=>{
    return arr.indexOf(item)===index
})
console.log(filterArray)

//使用reduce
const reduceArray=Array.prototype.reduce((accumulate,current)=>  {
    if (!accumulate.includes(current)) {
         accumulate.push(current)
    }
    return accumulate
}, [])
console.log(reduceArray)