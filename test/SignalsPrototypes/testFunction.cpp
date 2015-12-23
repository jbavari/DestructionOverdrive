#include <iostream>
#include <boost/function.hpp>
using std::cout;
using std::endl;
using std::cerr;


struct funcStruct
{
  /* Add's a to b */
  int operator()(int a, int b) const {return a+b;};
  float operator()(float a, float b) const {return a/b;};
};



int
main ( int argc, char** argv )
{
  boost::function<int (int x, int y)> f;
  boost::function2<int, int, int> g;

  boost::function<float (float x, float y)> h;
  boost::function2<float, float, float> j;

  funcStruct test;


  f = test;
  g = test;
  h = test;
  j = test;
  

  cout << "f: 2 + 5 = " << f(2, 5) << "\n";
  cout << "g: 2 + 5 = " << g(2, 5) << "\n";
  cout << "h: 2/5 = " << h(2, 5) << "\n";
  cout << "j: 2/5 = " << j(2, 5) << "\n";




  
  return 0;
}
