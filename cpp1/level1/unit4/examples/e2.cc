#include <iostream>


namespace Cpp1::Unit4::E2 {

  // ============= This usually place in a header file (*.h*) ==============
  class MyStr {
    int     m_maxLen;
    char*   m_data;

    void checkIndex(int index) const;

  public:
    MyStr(int maxLen);
    ~MyStr();

    int maxLen() const {return m_maxLen;}

    char get(int index) const;
    void set(int index, char ch);

    const char* data() const {return m_data;}
  };


  // ============= This usually placed in a source file (*.c*)
  MyStr::MyStr(int maxLen) {
    m_maxLen  = maxLen;
    m_data    = new char[maxLen+1];
  }

  MyStr::~MyStr() {
    delete m_data;
  }


  void MyStr::checkIndex(int index) const {
    if( index < 0 || index >= maxLen())
      throw std::runtime_error("Index is out limits");
  }


  char MyStr::get(int index) const {
    checkIndex(index);
    return m_data[index];
  }

  void MyStr::set(int index, char ch) {
    checkIndex(index);
    m_data[index] = ch;
  }
}


int main() {
  using namespace Cpp1::Unit4;

  E2::MyStr myStr(16);

  std::cerr << "Normal usage:" << std::endl;
  {
    int i = 0;

    for (; i < 5; ++i)
      myStr.set(i, 'A' + i);

    myStr.set(i, 0);
  }

  std::cerr << myStr.data() << std::endl;

  std::cerr << "attempting to go out of limits";
  for(int i = 0; i < 32; ++i) {
    std::cerr << "index=" << i << std::endl;
    myStr.set(i, 'A' + i);
  }
}
