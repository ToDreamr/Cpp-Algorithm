#include "../cunion.h"
class MyLinkedList {
    //类属性变量
private:
    int size;
    ListNode *head;
public:
    MyLinkedList() {
        this->size=0;
        this->head=new ListNode(0);
    }

    /**
     * 获取 index所在的值
     * @param index
     * @return
     */
    int get(int index) {
        //除去非法操作
        if (index<0||index>=size){
            return -1;
        }
        ListNode *dummyHead=head;
        int indexNode=0;
        while (indexNode<=index){
            dummyHead=dummyHead->next;
            index++;
        }
        return dummyHead->val;
    }

    /**
     * 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
     * @param val
     */
    void addAtHead(int val) {
        //虚拟头节点
        ListNode *dummyHead=new ListNode(0);//实例化头节点
        dummyHead->next=head;
        dummyHead->val=val;
        head=dummyHead;//更新头节点
    }

    /**
     * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
     * @param val
     */
    void addAtTail(int val) {
        ListNode *cur=head;
        while (cur->next!= nullptr){
            cur=cur->next;
        }
        ListNode *tail=new  ListNode(0);
        cur->next=tail;
        tail->val=val;
    }

    /**
     * void addAtIndex(int index, int val)
     * <h3>将一个值为 val 的节点插入到链表中下标为 index 的<b>节点之前。</b></h3>
     * 如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
     * @param index
     * @param val
     */
    void addAtIndex(int index, int val) {
        ListNode *cur=head;
        for (int i = 0; i < index; ++i) {
            cur=cur->next;
        }
        ListNode *tmp=new ListNode(0);
        cur->next=tmp;
        tmp->next=cur->next->next;
        tmp->val=val;
    }

    /**
     * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
     * @param index
     */
    void deleteAtIndex(int index) {
        //判断下标
        if (index<0||index>size){
            return;
        } else{
            ListNode *cur=head;
            for (int i = 0; i < index; ++i) {
                cur=cur->next;
            }
            cur=cur->next->next;
            delete(cur->next);
        }
    }
};