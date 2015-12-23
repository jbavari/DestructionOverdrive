#include <iostream>
#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
using std::cout;
using std::cerr;
using std::endl;

class HearsTickA
{
public:
  void sayHello(){cout<<"Hello\n";};
};


class HearsTickB
{
public:
  void sayGoodbye(){cout<<"Goodbye\n";};
};


int
main ( int argc, char** argv )
{
  HearsTickA a;
  HearsTickB b;
  boost::signal<void ()> sig;
  
  sig.connect(boost::bind(&HearsTickA::sayHello, boost::ref(a)));
  sig.connect(boost::bind(&HearsTickB::sayGoodbye, boost::ref(b)));

  sig();

  return 0;
}
