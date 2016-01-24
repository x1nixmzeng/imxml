#ifndef IMXML_H_
#define IMXML_H_

// Heavily inspired by yxml library by Yoran Heling
// to support parsing utf-16 text ranges

typedef enum
{
  kXmlHintUnknown,
  kXmlHintEnded,

  kXmlHintStartDeclaration,
  kXmlHintStartElementOpen,
  kXmlHintStartElementClose,
  kXmlHintStartAttributeName,
  kXmlHintStartAttributeValue,
  kXmlHintStartInnerText,

  kXmlHintDeclaration,
  kXmlHintElementOpen,
  kXmlHintElementClose,
  kXmlHintAttributeName,
  kXmlHintAttributeValue,
  kXmlHintInnerText,

  kXmlHintEndDeclaration,
  kXmlHintEndElementOpen,
  kXmlHintEndElementClose,
  kXmlHintEndAttributeName,
  kXmlHintEndAttributeValue,
  kXmlHintEndInnerText,

} XmlHint;

typedef struct XmlTextRange
{
  const short *begin;
  const short *end;
} XmlRange;

typedef struct XmlRange
{
  XmlRange range;
  const short* cursor;
  XmlHint context;
} Xml;

XmlHint xml_parse(Xml* xml);

#endif // IMXML_H_
