//暂时的死区：let and const 不生命无法使用
//var 函数级别的作用域，存在 变量级别的提升

//基本数据类型：string ，array，number,undefined,null,boolean,symbol


//null和undefined=》作为基本的应用类型，具有唯一的值，分别 作为null和undefined
//null只要用于 对象初始化操作，
// console.log(undefined==null)

//转换到字符串的操作
//字符转换为数字 类似java，使用number，parseInt函数
//parseFloat返回浮点数

function myFunction() {
    let inVariable = "函数内部变量";
    console.log(inVariable); // Uncaught ReferenceError: inVariable is not define
}
myFunction();//要先执行这个函数，否则根本不知道里面是啥
//块级别作用域，使用大括号包围的变量
//词法/静态作用域，js默认支持的

//原型，原型链模式
console.log(myFunction.prototype);

console.log(Array.prototype);

//原型链继承导致内存变量和空间共享，导致属性值混乱
//注意tyoeof无法判断null类型-》object
//实现自己的new方法
function mynew(Func, ...args) {
    // 1.创建一个新对象
    const obj = {}
    // 2.新对象原型指向构造函数原型对象
    obj.__proto__ = Func.prototype
    // 3.将构建函数的this指向新对象
    let result = Func.apply(obj, args)
    // 4.根据返回值判断
    return result instanceof Object ? result : obj
}
mynew(myFunction,"nihao")

//默认全局对象window
console.log(0.1+0.2)

//映用类型使用typeof都会 返回object
console.log(Object.is(null,undefined))
console.log(undefined)
console.log(typeof NaN)
console.log(isNaN(NaN));
console.log(Number.isNaN(NaN));