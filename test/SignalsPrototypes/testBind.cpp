#include <iostream>
#include <boost/function.hpp>
#include <boost/mem_fn.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
using std::cout;
using std::endl;
using std::cerr;


struct funcStruct
{
  /* Add's a to b */
  int operator()(int a, int b) const {return a+b;};
  float operator()(float a, float b) const {return a/b;};
  int mult(int a, int b){return a*b;};
};



int
main ( int argc, char** argv )
{
  boost::function<int (int x, int y)> f;
  boost::function2<int, int, int> g;

  boost::function<float (float x, float y)> h;
  boost::function2<float, float, float> j;

  boost::function<int (funcStruct& a, int x, int y)> k;
  boost::function3<int, funcStruct&, int, int> l;


  /* Function pointers for Bind */
  boost::function<int (int x, int y)> bf;
  boost::function2<int, int, int> bg;

  boost::function<float (float x, float y)> bh;
  boost::function2<float, float, float> bj;

  boost::function<int (int x, int y)> bk;
  boost::function2<int, int, int> bl;



  funcStruct test;

  /* Assigning Basic function objects */
  f = test;
  g = test;
  h = test;
  j = test;
  k = boost::mem_fn(&funcStruct::mult);
  l = boost::mem_fn(&funcStruct::mult);

  bf = boost::bind<int>(test, _1, _2);
  bg = boost::bind<int>(test, _1, _2);

  bh = boost::bind<float>(test, _1, _2);
  bj = boost::bind<float>(test, _1, _2);
  
  bk = boost::bind(&funcStruct::mult, boost::ref(test), _1, _2);
  bl = boost::bind(&funcStruct::mult, boost::ref(test), _1, _2);



  /* Output Basic function pointers */
  cout << "f: 2 + 5 = " << f(2, 5) << "\n";
  cout << "g: 2 + 5 = " << g(2, 5) << "\n";

  cout << "h: 2/5 = " << h(2, 5) << "\n";
  cout << "j: 2/5 = " << j(2, 5) << "\n";

  cout << "k: 2*5 = " << k(test, 2, 5) << "\n";
  cout << "l: 2*5 = " << l(test, 2, 5) << "\n";


  /* Output Bind function object */
  cout << "bf: 2 + 5 = " << bf(2, 5) << "\n";
  cout << "bg: 2 + 5 = " << bg(2, 5) << "\n";

  cout << "bh: 2 + 5 = " << bh(2, 5) << "\n";
  cout << "bj: 2 + 5 = " << bj(2, 5) << "\n";

  cout << "k: 2*5 = " << bk(2, 5) << "\n";
  cout << "l: 2*5 = " << bl(2, 5) << "\n";
  
  return 0;
}
