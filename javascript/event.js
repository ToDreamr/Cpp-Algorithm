//给父层元素绑定事件：
document.getElementById('list').addEventListener("click", function (e){
    // 兼容性处理
    const event = e || window.event;
    const target = event.target || event.srcElement;
    // 判断是否匹配目标元素
    if (target.nodeName.toLocaleLowerCase === 'li') {
        console.log('the content is: ', target.innerHTML);
    }
})