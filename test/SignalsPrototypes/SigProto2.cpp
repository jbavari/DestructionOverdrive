#include <iostream>
#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
using std::cout;
using std::cerr;
using std::endl;



class SendsTick
{
private:
  boost::signal0<void> sigTick;
public:
  void tick();
  boost::signals::connection connect(boost::signal0<void>::slot_function_type slot);
};



class HearsTickA
{
private:
  boost::signals::connection connectionTick;
public:
  HearsTickA( SendsTick& sender );
  ~HearsTickA();
  void sayHello(){cout<<"Hello\n";};
};


HearsTickA::HearsTickA( SendsTick& sender )
{
  boost::function0<void> f = boost::bind(&HearsTickA::sayHello, boost::ref(*this));
  connectionTick = sender.connect(f);
}

HearsTickA::~HearsTickA()
{
  if ( connectionTick.connected() )
    {
      connectionTick.disconnect();
    }
}

class HearsTickB
{
  boost::signals::connection connectionTick;
public:
  HearsTickB( SendsTick& sender );
  ~HearsTickB();
  void sayGoodbye(){cout<<"Goodbye\n";};
};


HearsTickB::HearsTickB( SendsTick& sender )
{
  connectionTick = sender.connect(boost::bind(&HearsTickB::sayGoodbye, boost::ref(*this)));
}

HearsTickB::~HearsTickB()
{
  if ( connectionTick.connected() )
    {
      connectionTick.disconnect();
    }
}



void
SendsTick::tick()
{
  sigTick();
}

boost::signals::connection
SendsTick::connect(boost::signal0<void>::slot_function_type slot)
{
  return sigTick.connect(slot);
}


int
main ( int argc, char** argv )
{
  SendsTick ticker;
  HearsTickA* a;
  HearsTickB* b;

  a = new HearsTickA(ticker);
  b = new HearsTickB(ticker);

  for ( int i = 0; i < 10; i++ )
    {
      ticker.tick();
    }

  delete a;

  for ( int i = 0; i < 10; i++ )
    {
      ticker.tick();
    }


  return 0;
}
