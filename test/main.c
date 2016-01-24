#include "xml.h"

const unsigned short xml_doc[] = L"<?xml version=\"1.0\"?><node></node>";

void xml_show_context(Xml* xml);

int main(int argc, char** argv)
{
  Xml inst;

  inst.range.begin = xml_doc;
  inst.range.end = xml_doc + sizeof(xml_doc) -1;

  inst.cursor = inst.range.begin;
  inst.context = kXmlHintUnknown;

  while( xml_parse(&inst) != kXmlHintEnded ) {
    xml_show_context(&inst);
  }

  return 0;
}

void xml_show_context(Xml* xml)
{
  unsigned short pos;

  pos = xml->cursor - xml->range.begin;

#define WRITE_HINT(hint) case hint: printf( #hint ); break;

  switch( xml->context ) {
    WRITE_HINT(kXmlHintEnded)
    WRITE_HINT(kXmlHintStartDeclaration)
    WRITE_HINT(kXmlHintStartElementOpen)
    WRITE_HINT(kXmlHintStartElementClose)
    WRITE_HINT(kXmlHintStartAttributeName)
    WRITE_HINT(kXmlHintStartAttributeValue)
    WRITE_HINT(kXmlHintStartInnerText)
    WRITE_HINT(kXmlHintDeclaration)
    WRITE_HINT(kXmlHintElementOpen)
    WRITE_HINT(kXmlHintElementClose)
    WRITE_HINT(kXmlHintAttributeName)
    WRITE_HINT(kXmlHintAttributeValue)
    WRITE_HINT(kXmlHintInnerText)
    WRITE_HINT(kXmlHintEndDeclaration)
    WRITE_HINT(kXmlHintEndElementOpen)
    WRITE_HINT(kXmlHintEndElementClose)
    WRITE_HINT(kXmlHintEndAttributeName)
    WRITE_HINT(kXmlHintEndAttributeValue)
    WRITE_HINT(kXmlHintEndInnerText)
  }

#undef WRITE_HINT
  
  printf(" @ 0x%04X\n", pos);
}
