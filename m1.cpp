#include<iostream>
#include<string.h>

using namespace std;
class CMyString{
    public: CMyString(char* pData=nullptr){m_pData=pData;}
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator=(const CMyString &str){
        if(this!=&str){
            CMyString temp(str);
            char *stemptr = temp.m_pData;
            temp.m_pData = m_pData;
            m_pData = stemptr;
            //为了保证安全，再复制出错的时候不丢失原有的值
            // char* tt = new char[(strlen(str.m_pData)+1)];
            // tt = str.m_pData;
            // m_pData = tt;
            // strcpy(m_pData,tt);

        }
        return *this;
    }
    void print(){
        cout << m_pData <<endl;
    }
    private:
        char *m_pData;
};
//新增赋值运算符函数

int main(int argc, char const *argv[])
{
    //CMyString m1;
    //char const *t = "aaa";
   // CMyString m2;
    cout <<"aaa"<<endl;
    //m1=m2;a
    cout<< "bbb"<<endl;
    //m1.print();
    return 0;
}
