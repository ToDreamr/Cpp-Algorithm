/**
 * Promise 是异步编程的一种解决方案，其实是一个构造函数，自己身上有all、reject、
 * resolve这几个方法，实例对象上有then、catch等方法。所谓Promise，简单说就是一个容器，里面保存着某个未来才会结束的事件（通常是一个异步操作，如ajax请求）的结果
 */

/**
 *
 * （1）对象的状态不受外界影响。有三种状态：pending（进行中）、fulfilled（已成功）、rejected（已失败）。
 * 只有异步操作的结果，可以决定当前是哪一种状态，任何其他操作都无法改变这个状态。这也是Promise这个名字的由来，它的英语意思就是“承诺”，表示其他手段无法改变。
 *
 * （2）一旦状态改变，就不会再变，任何时候都可以得到这个结果。Promise对象的状态改变，只有两种可能：从pending变
 * 为fulfilled和从pending变为rejected。只要这两种情况发生，状态就凝固了，不会再变了，会一直保持这个结果，这时就称为 resolved（已定型）。如果
 * 改变已经发生了，你再对Promise对象添加回调函数，也会立即得到这个结果。这与事件（Event）完全不同，事件的特点是，如果你错过了它，再去监听，是得不到结果的。
 */

//参数：

// const promise = new Promise(function(resolve, reject) {
//     // ... some code
//     if (true){
//         resolve(value);
//     } else {
//         reject(error);
//     }
// });
//
// promise.then(function(value) {
//     // success
// }, function(error) {
//     // failure
// });
//
// promise.then((value) => {
//     // success
// }, (error) => {
//     // failure
// });

    //新建的promise函数立即执行
let promise = new Promise(function(resolve, reject) {
    console.log('Promise');
    resolve();
});

promise.then(function() {
    console.log('resolved.');
});
// sleep(5)
console.log('Hi!');
// Promise
// Hi!
// resolved


//优点：链式 调用，可在后面继续完成then的操作
function buy(){
    console.log("start buying pen")
    var promise=new Promise(function (resolve, reject) {
        setTimeout(function (){
            console.log("buying a book")
            resolve("homework");
        },1000);
    })
    return promise;
}

function work(data){
    console.log("starting doing "+data );
    var promise=new Promise(function (resolve, reject) {
        setTimeout(function () {
            console.log("did homework")
            resolve("book")
        },1000);
    })
    return promise;
}


function out(data){
    console.log("开始上交："+data);
    var p = new Promise(function(resolve,reject){
        setTimeout(function(){
            console.log("上交完毕");
            resolve("得分：A");
        },1000);
    });
    return p;
}

buy().then(work).then(out).then(function (data){
    console.log(data)
})

//promise.all()把所有的参数内promise合在一起，同时可以获取每个实例promise的返回值，
// 但需要等待所有的promise完成后resolved才会返回 结果，或者任何一个rejected

// Promise.all([buy(),work(),out()]).then(value => {
//     console.log(value)
// })

//涉及到 异步操作：
//涉及到异步操作，需要在方法内部返回一个 Promise
//对象或者使用 async/await 等方式，以确保异步操作完成后返回数据