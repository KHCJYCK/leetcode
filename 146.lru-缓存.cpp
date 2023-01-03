/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    class Node{
        public:
            int key, val;
            Node* next, *prev;
            Node(int k, int v):key(k),val(v),
            next(nullptr),prev(nullptr){}
    };
    class DoubleList{
        private:
            Node* head,*tail;
            int _size;
        public:
            DoubleList(){
                head = new Node(0,0);
                tail = new Node(0,0);
                head->next = tail;
                tail->prev = head;
                _size = 0;
            }
            Node* push_back(int k, int v){
                Node* element = new Node(k, v);
                element->prev = tail->prev;
                tail->prev->next = element;
                tail->prev = element;
                element->next = tail;
                _size++;
                return element;
            }
            void remove(Node* element){
                element->prev->next = element->next;
                element->next->prev = element->prev;
                _size--;
            }
            Node* pop_front(){
                if(head->next == tail)
                    return nullptr;
                Node* first = head->next;
                remove(first);
                return first;
            }
            int size(){
                return _size;
            }
            ~DoubleList(){
                Node* temp = head;
                while(temp != nullptr){
                    Node* next = temp->next;
                    delete temp;
                    temp = next;
                }
            }
    };
    DoubleList cache;
    int cap;
    unordered_map<int, Node*> map;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }  
    int get(int key) {
        if(map.find(key) != map.end()){
            int val = map[key]->val;
            cache.remove(map[key]);
            Node* element = cache.push_back(key, val);
            map[key] = element;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            cache.remove(map[key]);
            Node* element = cache.push_back(key, value);
            map[key] = element;
            return;
        }
        Node* element = cache.push_back(key,value);
        map.insert({key, element});
        if(cache.size() > cap){
            Node* element = cache.pop_front();
            map.erase(element->key);
            delete element;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

