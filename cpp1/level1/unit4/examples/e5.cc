#include <iostream>
#include <cstring>


namespace Cpp1::Unit4::E5 {

  // ============= This usually place in a header file (*.h*) ==============
  class MyStr {
    int     m_maxLen;
    char*   m_data;

    void allocate(int maxLen);
    void copy(const char* cstr);
    void checkIndex(int index) const;

  public:
    MyStr(int maxLen);
    MyStr(const char* cstr);
    ~MyStr();

    int maxLen() const {return m_maxLen;}

    char get(int index) const;
    char& at(int index);
    void set(int index, char ch);

    MyStr& operator= (const MyStr& str2) { copy(str2.data()); return *this;}

    const char* data() const {return m_data;}

    char operator[] (int index) const { return get(index); }
    char& operator[] (int index) { return at(index); }
  };


  inline std::ostream& operator<< (std::ostream& os, const MyStr& str) {
    os << str.data();
    return os;
  }


  // ============= This usually placed in a source file (*.c*)
  MyStr::MyStr(int maxLen) {
    m_data = 0;
    m_maxLen = 0;
    allocate(maxLen);
  }

  MyStr::MyStr(const char* cstr) {
    m_data = 0;
    m_maxLen = 0;
    copy(cstr);
  }

  MyStr::~MyStr() {
    delete m_data;
  }

  void MyStr::allocate(int maxLen) {
    if(m_data != nullptr)
      delete m_data;

    m_data    = new char[maxLen+1];
    m_maxLen  = maxLen;
  }

  void MyStr::copy(const char* cstr) {
    allocate(strlen(cstr));
    strcpy(m_data, cstr);
  }

  void MyStr::checkIndex(int index) const {
    if( index < 0 || index >= maxLen())
      throw std::runtime_error("Index is out limits");
  }


  char MyStr::get(int index) const {
    checkIndex(index);
    return m_data[index];
  }

  char& MyStr::at(int index) {
    checkIndex(index);
    return m_data[index];
  }

  void MyStr::set(int index, char ch) {
    checkIndex(index);
    m_data[index] = ch;
  }

  void reverse(MyStr& str) {
    int l = 0, r = str.maxLen() - 1;

    while(l < r) {
      char tmp = str[l];
      str[l] = str[r];
      str[r] = tmp;

      l++;
      r--;
    }
  }
}


int main() {
  using namespace Cpp1::Unit4;


  std::cout << "Normal usage:" << std::endl;
  E5::MyStr myStr = "hello";
  std::cout << "#1: " << myStr << std::endl;

  E5::reverse(myStr);
  std::cout << "#2: " << myStr << std::endl;
}
