//
// Created by 春江花朝秋月夜 on 2024/4/2.
//
/**
 *  使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

    实现 MyQueue 类：

    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false
    说明：

    你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 */
#include "iostream"
#include "stack"
#include "vector"
using namespace std;
class MyQueue {
    /**
     * 输入：
        ["MyQueue", "push", "push", "peek", "pop", "empty"]
        [[], [1], [2], [], [], []]
        输出：
        [null, null, null, 1, 1, false]

        解释：
        MyQueue myQueue = new MyQueue();
        myQueue.push(1); // queue is: [1]
        myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
        myQueue.peek(); // return 1
        myQueue.pop(); // return 1, queue is [2]
        myQueue.empty(); // return false
     */
public:
    stack<int ,vector<int> > queueInStack;//用于插入元素队列的栈
    stack<int ,vector<int> > queueOutStack;//用于取出元素队列的栈
    MyQueue() {

    }

    void push(int x) {
        queueInStack.push(x);
    }

    int pop() {
        //需要取出元素的时候，先把进入队列的元素加入其中
        if (!queueInStack.empty()){
            while (!queueInStack.empty()){
                queueOutStack.push(queueInStack.top());
                queueInStack.pop();
            }
        }
        int res=queueOutStack.top();
        queueOutStack.pop();
        return res;
    }

    int peek() {
        //只取出顶部元素但是不抛出
        int res=this->pop();
        this->push(res);
        return res;
    }

    bool empty() {
        return queueInStack.empty()&&queueOutStack.empty();//全为空，则返回true
    }
};