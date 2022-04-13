#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
private:
    int N[1010];
    int pre = 0, cur = 0;
    int max;
public:
    MyCircularDeque(int k) {
        max = k;
    }

    bool insertFront(int value) {
        if (cur > pre) {
            if (cur - pre == max) return false;
        }
        else {
            if (1010 - pre + cur == max) return false;
        }
        //if (abs(pre - cur)%1010 == max) return false;
        //头部插入
        if (pre == 0) {
            pre = 1010 - 1;
        }
        else pre--;
        N[pre] = value;
        return true;
    }

    bool insertLast(int value) {
        if (cur > pre) {
            if (cur - pre == max) return false;
        }
        else {
            if (1010 - pre + cur == max) return false;
        }
        N[cur] = value;
        cur = (cur + 1) % 1010;
        return true;
    }

    bool deleteFront() {
        if (cur == pre) return false;
        else{
            pre++;
            pre = pre%1010;
        }
        return true;
    }

    bool deleteLast() {
        if (cur == pre) return false;
        if(cur==0) cur=1009;
        else cur--;
        return true;
    }

    int getFront() {
        return cur == pre ? -1 : N[pre];
    }

    int getRear() {
        if(cur==0){
            return cur == pre ? -1 : N[1009];
        }
        else return cur == pre ? -1 : N[cur - 1];
    }

    bool isEmpty() {
        return cur == pre;
    }

    bool isFull() {
        return cur>=pre? (cur-pre)==max: (1010-pre+cur)==max;
    }
};

int main() {
    MyCircularDeque mc(5);
    mc.insertFront(7);
    mc.insertLast(0);
    cout<<mc.getFront()<<" ";
    mc.insertLast(3);
    cout<<mc.getFront()<<" ";
    mc.insertFront(9);
    cout<<mc.getRear()<<" ";
    mc.insertFront(4);
    int c = mc.getRear();
}
