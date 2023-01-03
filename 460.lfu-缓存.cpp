/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class LFUCache {
public:
    class Node{
    public:
        Node* prev, *next;
        int key, val, freq;
        Node(int k, int v):key(k),val(v),freq(1),prev(nullptr),next(nullptr){}
    };
    class DoubleLinkList{
    public:
        Node* head, *tail;
        DoubleLinkList(){
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
        }
        void addNode(Node* element){
            tail->prev->next = element;
            element->next = tail;
            element->prev = tail->prev;
            tail->prev = element;
        }
        void removeNode(Node* element){
            element->prev->next = element->next;
            element->next->prev = element->prev;
        }
    };
    int cap, size, minfreq;
    unordered_map<int, Node*> kv;
    unordered_map<int, DoubleLinkList*> fl;
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    int get(int key) {
        if(kv.find(key) == kv.end())
            return -1;
        Node* element = kv[key];
        Infreq(element);
        return element->val;
    }
    void put(int key, int value) {
        if(cap == 0)
            return;
        //update
        if(kv.find(key) != kv.end()){
            Node* element = kv[key];
            kv[key]->val = value;
            Infreq(element);
            return;
        }
        //insert
        //delete the minfreq node
        if(size == cap){
            DoubleLinkList* minList = fl[minfreq];
            Node* del = minList->head->next;
            kv.erase(del->key);
            minList->removeNode(del);
            size--;
        }
        Node* element = new Node(key, value);
        kv.insert({key, element});
        if(fl.find(element->freq) == fl.end()){
            DoubleLinkList* l = new DoubleLinkList();
            l->addNode(element);
            fl.insert({element->freq, l});
        }
        else{
            DoubleLinkList* l = fl[element->freq];
            l->addNode(element);
        }
        size++;
        minfreq = 1;
    }
    void Infreq(Node* node){
        int freq = node->freq;
        DoubleLinkList* l = fl[freq];
        if(freq == minfreq && node->prev == l->head && node->next == l->tail)
            minfreq++;
        l->removeNode(node);
        node->freq++;
        if(fl.find(freq + 1) != fl.end()){
            fl[freq + 1]->addNode(node);
        }else{
            DoubleLinkList* new_list = new DoubleLinkList();
            new_list->addNode(node);
            fl.insert({freq + 1, new_list});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

