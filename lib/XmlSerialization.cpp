#include <string.h>
#include <iostream>
#include <sstream>
#include <errno.h>
#include "XmlSerialization.h"
using std::cout;
using std::cerr;
using std::endl;
using std::ostringstream;


namespace LightningDev
{
  const char* 
  XmlSerialization::getIndent(unsigned int number)
  {
    static char buff[512];
    unsigned int numSpaces = INDENT*number;
    

    if (numSpaces+1 > 512)
      {
	cerr<<"numSpaces in XmlSerialization::getIndent is larger than buff, making it fit"<<endl;
	numSpaces = 511;
      }
    
    buff[numSpaces] = 0;
	
    for(unsigned int i = 0; i < numSpaces; i++)
      {
	buff[i] = ' ';
      }

    return buff;
  }

  const char*
  XmlSerialization::getAttributeName(xmlNodePtr inNode)
  {
    xmlAttr* curAttr;

    for (curAttr=inNode->properties; curAttr != 0; curAttr=curAttr->next )
      {
	if ( strcmp ( (const char*)curAttr->name, "name" ) == 0 )
	  {
	    /* Now we are in the a attribute */
	    return (const char*)curAttr->children->content;
	  }
      }
    return "";
  }

  const char*
  XmlSerialization::getAttributeType(xmlNodePtr inNode)
  {
    xmlAttr* curAttr;
    
    for (curAttr = inNode->properties; curAttr != 0; curAttr=curAttr->next )
      {
	if ( strcmp ( (const char*)curAttr->name, "type" ) == 0 )
	  {
	    /* Now we are in the a attribute */
	    return (const char*)curAttr->children->content;
	  }
      }
    return "";
  }


  void
  XmlSerialization::getStartAttributeElement(unsigned int indent, const char* name, 
					     const char*  type,   ostream&    retStream)
  {
    retStream << XmlSerialization::getIndent(indent);
    retStream << "<attribute name=\"" << name << "\" type=\""<<type<<"\">";
  }
  

  void
  XmlSerialization::getEndAttributeElement(unsigned int indent, ostream& retStream)
  {
    retStream << "</attribute>\n";
  }


  void
  XmlSerialization::getIntAttributeElement(unsigned int indent, const char* name, 
					   const int    value,  ostream&    retStream)
  {
    getStartAttributeElement(indent, name, "int", retStream);
    retStream << value;
    getEndAttributeElement(indent, retStream);
  }



  /**
   * MUST BE LOWER CASE TRUE AND FALSE!!!!!!!
   * Borland has no strcascmp();
   */
  void
  XmlSerialization::getBoolAttributeElement(unsigned int indent, const char* name, 
					    bool         value,  ostream&    retStream)
  {
    getStartAttributeElement(indent, name, "bool", retStream);
    if ( value )
      {
	retStream << "true";
      }
    else
      {
	retStream << "false";
      }
    getEndAttributeElement(indent, retStream);
  }


  void
  XmlSerialization::getULIntAttributeElement(unsigned int           indent, const char* name, 
					     const unsigned long int value,  ostream&    retStream)
  {
    getStartAttributeElement(indent, name, "ULInt", retStream);
    retStream << value;
    getEndAttributeElement(indent, retStream);
  }


  void
  XmlSerialization::getFloatAttributeElement(unsigned int  indent, const char* name, 
					     const float   value,  ostream&    retStream)
  {
    getStartAttributeElement(indent, name, "float", retStream);
    retStream << value;
    getEndAttributeElement(indent, retStream);
  }


  void
  XmlSerialization::getCStrAttributeElement(unsigned int indent, const char* name, 
					    const char*  value,  ostream&    retStream)
  {
    getStartAttributeElement(indent, name, "CStr", retStream);
    retStream << value;
    getEndAttributeElement(indent, retStream);
  }



  void
  XmlSerialization::getObjAttributeElement(unsigned int indent, const char*             name, 
					   const char*  type,   const XmlSerialization& value, 
					   ostream&     retStream)
  {
    getStartAttributeElement(indent, name, type, retStream);
    retStream << "\n";
    value.getXml(indent+1, retStream);
    retStream << XmlSerialization::getIndent(indent);
    getEndAttributeElement(indent, retStream);
  }



  void
  XmlSerialization::getStartObjectElement(unsigned int indent, const char* type, 
					  ostream&     retStream)
  {
    retStream << XmlSerialization::getIndent(indent);
    retStream << "<object type=\"" << type << "\">\n";
  }
  

  void
  XmlSerialization::getEndObjectElement(unsigned int indent, ostream& retStream)
  {
    retStream << XmlSerialization::getIndent(indent);
    retStream << "</object>\n";
  }

  void
  XmlSerialization::getStartParentsElement(unsigned int indent, ostream& retStream)
  {
    retStream << XmlSerialization::getIndent(indent);
    retStream << "<parents>\n";
  }
  

  void
  XmlSerialization::getEndParentsElement(unsigned int indent, ostream& retStream)
  {
    retStream << XmlSerialization::getIndent(indent);
    retStream << "</parents>\n";
  }


  XmlSerialization::~XmlSerialization()
  {}

  
  xmlNodePtr
  XmlSerialization::getParentsObjectNode(xmlNodePtr inNode, const char* thisType)
  {
    xmlNodePtr curNode = inNode;
    

    for (curNode = inNode->children; curNode != 0; curNode = curNode->next )
      {
	if ( strcmp((const char*)curNode->name, "parents") == 0 )
	  {
	    /* What we're looking for */
	    break;
	  }
      }

    if ( curNode == 0 )
      {
	/* There is no parents node here */
	throw XmlSerializationException("No Parents Node Found!");
      }
    

    /* curNode now points at the parents element. */
    for (curNode = curNode->children; curNode != 0; curNode = curNode->next )
      {
	if ( strcmp ( getAttributeType(curNode), thisType ) == 0 )
	  {
	    return curNode;
	  }
      }

    throw XmlSerializationException("Could not find parents node of correct type!");
  }


  xmlNodePtr
  XmlSerialization::getObjectAttributeObject(xmlNodePtr inNode, const char* thisName)
  {
    xmlNodePtr curNode;

    for (curNode = inNode->children; curNode != 0; curNode = curNode->next )
      {
	if(strcmp ( getAttributeName(curNode), thisName ) == 0 )
	  {
	    return curNode->children->next;
	  }
      }

    throw XmlSerializationException("Could not find attribute of this name!");
  }

  char*
  XmlSerialization::getCStrAttributeCopy(xmlNodePtr inNode)
  {
    char* tmp;
    tmp = new char[strlen((const char*)inNode->children->content)+1];
    strcpy(tmp, (const char*)inNode->children->content);
    return tmp;
  }

  const char*
  XmlSerialization::getCStrAttributeValue(xmlNodePtr inNode)
  {
    return (const char*)inNode->children->content;
  }


  long int 
  XmlSerialization::getIntAttributeValue(xmlNodePtr inNode)
  {
    char* tail = 0;
    long int retVal;

    errno = 0;
    retVal = strtol((char*)inNode->children->content, &tail, 10);
    if ( errno !=0 )
      {
	cerr << "Problem with strtoll";
	abort();
      }

    return retVal;
  }



  bool
  XmlSerialization::getBoolAttributeValue(xmlNodePtr inNode)
  {
    if (strcasecmp((char*)inNode->children->content, "true") == 0 )
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool 
  XmlSerialization::getBoolAttributeValueByName(xmlNodePtr inNode, const char* name)
  {
    xmlNodePtr curNode;
    
    for (curNode=inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp ( (const char*)curNode->name, "attribute" ) == 0 &&
	     strcmp( (const char*)getAttributeName(curNode), name ) == 0 && 
	     strcmp( (const char*)getAttributeType(curNode), "bool" ) == 0 )
	  {
	    return getBoolAttributeValue(curNode);
	  }
      }
    throw XmlSerializationException("Boolean Attribute node with name not found!");
  }



  float
  XmlSerialization::getFloatAttributeValueByName(xmlNodePtr inNode, const char* name)
  {
    xmlNodePtr curNode;
    
    for (curNode=inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp ( (const char*)curNode->name, "attribute" ) == 0 &&
	     strcmp( (const char*)getAttributeName(curNode), name ) == 0 && 
	     strcmp( (const char*)getAttributeType(curNode), "float" ) == 0 )
	  {
	    return getFloatAttributeValue(curNode);
	  }
      }
    throw XmlSerializationException("Float Attribute node with name not found!");
  }
  



  const char*
  XmlSerialization::getCStrAttributeValueByName(xmlNodePtr inNode, const char* name)
  {
    xmlNodePtr curNode;
    
    for (curNode=inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp ( (const char*)curNode->name, "attribute" ) == 0 &&
	     strcmp( (const char*)getAttributeName(curNode), name ) == 0 && 
	     strcmp( (const char*)getAttributeType(curNode), "CStr" ) == 0 )
	  {
	    return getCStrAttributeValue(curNode);
	  }
      }
    throw XmlSerializationException("CStr Attribute node with name not found!");
  }


  int
  XmlSerialization::getIntAttributeValueByName(xmlNodePtr inNode, const char* name)
  {
    xmlNodePtr curNode;
    
    for (curNode=inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp ( (const char*)curNode->name, "attribute" ) == 0 &&
	     strcmp( (const char*)getAttributeName(curNode), name ) == 0 && 
	     strcmp( (const char*)getAttributeType(curNode), "int" ) == 0 )
	  {
	    return getIntAttributeValue(curNode);
	  }
      }
    throw XmlSerializationException("Int Attribute node with name not found!");
  }


  unsigned long int
  XmlSerialization::getULIntAttributeValueByName(xmlNodePtr inNode, const char* name)
  {
    xmlNodePtr curNode;
    
    for (curNode=inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp ( (const char*)curNode->name, "attribute" ) == 0 &&
	     strcmp( (const char*)getAttributeName(curNode), name ) == 0 && 
	     strcmp( (const char*)getAttributeType(curNode), "ULInt" ) == 0 )
	  {
	    return getULIntAttributeValue(curNode);
	  }
      }
    throw XmlSerializationException("ULInt Attribute node with name not found!");
  }


  unsigned long int 
  XmlSerialization::getULIntAttributeValue(xmlNodePtr inNode)
  {
    char* tail = 0;
    long unsigned int retVal;

    errno = 0;
    retVal = strtoul((char*)inNode->children->content, &tail, 10);
    if ( errno !=0 )
      {
	cerr << "Problem with strtoul";
	abort();
      }

    return retVal;
  }

  float
  XmlSerialization::getFloatAttributeValue(xmlNodePtr inNode)
  {
    char* tail = 0;
    float retVal;

    errno = 0;
    retVal = strtof((char*)inNode->children->content, &tail);
    if ( errno !=0 )
      {
	cerr << "Problem with strtoul";
	abort();
      }

    return retVal;
  }

  const xmlChar* 
  XmlSerialization::getXml(unsigned int baseIndent) const
  {
    static ostringstream retStream;
    static char *retVal = 0;

    retStream.str("");
    
    getXml(baseIndent, retStream);


    if( retVal != 0 )
      {
        delete retVal;
      }

    retVal = new char[ retStream.str().size() ];
    strcpy( retVal, retStream.str().c_str() );

    return (xmlChar*)retVal;
  }

}
