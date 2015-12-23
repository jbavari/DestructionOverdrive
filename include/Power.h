/* -*-c++-*- */
#ifndef LD_POWER_H
#define LD_POWER_H 1
#include "XmlSerialization.h"
#include <limits.h>

namespace LightningDev
{

  /**
   * Power is an abstraction of the physics concept of power.
   * Reactors provide a constant supply of power, and other modules
   * consume an amount of power.  We shall use the unit Joule to
   * describe quantities of power, but the resemblance with
   * actual physics stops there.
   *
   * The properties of this class are subtaly different from those of
   * an unsigned integer allowing the effective use of a constant
   * reference into this object.
   *
   * In the event amount would be decremented to less than 0, set
   * amount to zero.  If it would be set above UNSIGNED_INT_MAX, 
   * set amount ot UNSIGNED_INT_MAX
   */
  class Power : virtual public XmlSerialization
  {
  private:
    /** Amount of power in Joules, if you want a decimal, round up */
    unsigned long int amount;



    friend Power operator+(const Power& a, const Power&b);
    friend Power operator-(const Power& a, const Power&b);
    friend Power operator*(const Power& a, const Power&b);
    friend Power operator/(const Power& a, const Power&b);
    friend Power operator%(const Power& a, const Power&b);
    friend bool operator>(const Power& a, const Power& b);
    friend bool operator>=(const Power& a, const Power&b);
    friend bool operator<(const Power& a, const Power&b);
    friend bool operator<=(const Power& a, const Power&b);
    friend bool operator!=(const Power& a, const Power&b);
    friend bool operator==(const Power& a, const Power&b);
    
  public:
    /**
     * The primary constructor.  It initilizes amount to initAmount, or
     * to zero.
     *
     *
     * @param initAmount unsigned int which defaults to zero.  The amount of power in Joules.
     */
    Power(unsigned long int initAmount = 0);

    /**
     * The copy constructor.  It creates a copy, or a clone, of the Power instance, toCopy.
     *
     * @param toCopy const Power& reffering to the power instance to copy. 
     */
    Power(const Power& toCopy);





    /**
     * From XmlSerialization
     */
    const xmlChar* getXml(unsigned int baseIndent=0) const;

    /**
     * From XmlSerialization
     */
    void getXml(unsigned int baseIndent, ostream& retStream) const;

    /**
     * Constructs power from an xmlNodePtr at a Power object node.
     *
     * @param inNode xmlNodePtr to the object node of type Power.
     */
    Power(xmlNodePtr inNode);


    /**
     * Returns the current value of amount.
     *
     * @return unsigned int copy of the value of amount.
     */
    unsigned long int getAmount() const;

    /**
     * Sets the value of amount.
     *
     * @param newAmount unsigned int value to set amount to.
     */
    void setAmount(unsigned long int newAmount);

    Power& operator+=(const Power& a);
    Power& operator-=(const Power& a);
    Power& operator*=(const Power& a);
    Power& operator/=(const Power& a);
    Power& operator%=(const Power& a);
    Power& operator=(const Power& a);
    Power& operator++();
    Power& operator++(int postfixDummy);
    Power& operator--();
    Power& operator--(int postfixDummy);
  };


  Power operator+(const Power& a, const Power&b);
  Power operator-(const Power& a, const Power&b);
  Power operator*(const Power& a, const Power&b);
  Power operator/(const Power& a, const Power&b);
  Power operator%(const Power& a, const Power&b);
  bool operator>(const Power& a, const Power& b);
  bool operator>=(const Power& a, const Power&b);
  bool operator<(const Power& a, const Power&b);
  bool operator<=(const Power& a, const Power&b);
  bool operator!=(const Power& a, const Power&b);
  bool operator==(const Power& a, const Power&b);
}

#endif /* LD_POWER_H */
