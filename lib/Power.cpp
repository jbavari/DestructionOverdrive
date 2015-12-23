#include "Power.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;


namespace LightningDev
{

  using namespace std;

  Power::Power(unsigned long int initAmount)
  {
    amount=initAmount;  
  }

  Power::Power(const Power& toCopy)
  {
    amount=toCopy.amount;
  }

  unsigned long int Power::getAmount() const
  {
    return amount;
  }

  void Power::setAmount(unsigned long int newAmount)
  {
    amount=newAmount;
  }

  Power& Power::operator+=(const Power& a)
  {
    /** copy the implicit parameter */
    *this = (*this)+a;
    return *this;
  }

  Power& Power::operator-=(const Power& a)
  {
    /** copy the implicit parameter */
    *this = (*this)-a;
    return *this;
  }

  Power& Power::operator*=(const Power& a)
  {
    /** copy the implicit parameter */
    Power result(*this);
    result=result*a;
    *this=result;
    return *this;
  }

  Power& Power::operator/=(const Power& a)
  {
    /** copy the implicit parameter */
    Power result(*this);
    result=result/a;
    *this=result;
    return *this;
  }

  Power& Power::operator%=(const Power& a)
  {
    /** copy the implicit parameter */
    Power result = *this;
    result=result%a;
    *this=result;
    return *this;
  }

  Power& Power::operator=(const Power& a)
  {
    if(this != &a){
      amount=a.amount;        
    }
    return *this;
  }

  Power& Power::operator++()
  {
    if ( amount + 1 == 0 )
      {
	return *this;
      }
    amount++;
    return *this;
  }

  Power& Power::operator++(int postfixDummy)
  {
    if ( amount + 1 == 0 )
      {
	return *this;
      }
    amount++;
    return *this;
  }

  Power& Power::operator--()
  {
    if ( amount == 0 )
      {
	return *this;           
      }

    amount--;        

    return *this;
  }

  Power& Power::operator--(int postfixDummy)
  {
    amount--;
    return *this;
  }

  Power operator+(const Power& a, const Power&b)
  {
    Power result;
    
    if ( a.amount + b.amount < a.amount )
      {
	result = (unsigned long int)0 - 1;
      }
    else
      {
	result = a.amount + b.amount;
      }
    
    return result;
  }

  Power operator-(const Power& a, const Power& b)
  {
    Power result;
  
    if ( (a.amount - b.amount ) > a.amount )
      {
	/* We've gone below zero and back to the top, set it to zero */
	result.amount = 0;                
      }
    else
      {
	result.amount = a.amount - b.amount;
      }
    
    return result;
  }

  Power operator*(const Power& a, const Power&b)
  {
    Power result = Power(a.getAmount()* b.getAmount());
    return result;
  }

  Power operator/(const Power& a, const Power&b)
  {
    Power result = Power(a.getAmount()/ b.getAmount());
    return result;
  }  

  Power operator%(const Power& a, const Power&b)
  {
    Power result = Power(a.getAmount()% b.getAmount());
    return result;
  }

  bool operator>(const Power& a, const Power& b)
  {
    return (a.getAmount() > b.getAmount());
  }

  bool operator>=(const Power& a, const Power&b)
  {
    return (a.getAmount() >= b.getAmount());
  }

  bool operator<(const Power& a, const Power&b)
  {
    return (a.getAmount() < b.getAmount());
  }

  bool operator<=(const Power& a, const Power&b)
  {
    return (a.getAmount() <= b.getAmount());
  }

  bool operator!=(const Power& a, const Power&b)
  {
    return (a.getAmount() != b.getAmount());
  }

  bool operator==(const Power& a, const Power&b)
  {
    return (a.getAmount() == b.getAmount());
  }


  /******************************************************
   *         From XmlSerializable                       *
   ******************************************************/
  const xmlChar* 
  Power::getXml(unsigned int baseIndent) const
  {
    static ostringstream retStream;
    retStream.str("");
    
    getXml(baseIndent, retStream);

    return (const xmlChar*)retStream.str().c_str();
  }
  
  void 
  Power::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "Power", retStream);
    getULIntAttributeElement(baseIndent+1, "amount", amount, retStream);
    getEndObjectElement(baseIndent, retStream);
  }

  Power::Power(xmlNodePtr inNode)
  {
    for ( xmlNodePtr curNode = inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp(getAttributeName(curNode), "amount") == 0 )
	  {
	    amount = getULIntAttributeValue(curNode);
	  }
      }
  }
  

  

} /* end namespace LightningDev */
