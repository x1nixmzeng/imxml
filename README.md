# ImXML

ImXml is a lightweight in-memory XML parser.

* Single API method
* No allocations
* Range based parsing
* Supporting (only) UTF-16

The library was inspired by the yaml library by Yoran Heling.


## Usage

* Create a range for your XML input
* Repeatedly call **xml_parse** until you are returned `kXmlHintEnded`

Hints are returned for the following contexts:

| Enum                         | Description                | Example      |
|------------------------------|----------------------------|--------------|
| kXmlHintEnded                | End of range               | `N/A`        |
| kXmlHintStartDeclaration     | Start of declaration       | `<?`         |
| kXmlHintStartElementOpen     | Start of opening element   | `<`          |
| kXmlHintStartElementClose    | Start of closing element   | `</`         |
| kXmlHintStartAttributeName   | Start of attribute name    | `version`    |
| kXmlHintStartAttributeValue  | Start of attribute value   | `1.0`        |
| kXmlHintStartInnerText       | Start of inner text        | `Inner text` |
| kXmlHintDeclaration          | Continued declaration      | `xml`        |
| kXmlHintElementOpen          | Continued opening element  | `node`       |
| kXmlHintElementClose         | Continued closing element  | `node`       |
| kXmlHintAttributeName        | Continued attribute name   | `version`    |
| kXmlHintAttributeValue       | Continued attribute value  | `1.0`        |
| kXmlHintInnerText            | Continued inner text       | `Inner text` |
| kXmlHintEndDeclaration       | End of declaration         | `?>`         |
| kXmlHintEndElementOpen       | End of opening element     | `>`          |
| kXmlHintEndElementClose      | End of closing element     | `>`          |
| kXmlHintEndAttributeName     | End of attribute name      | `=`          |
| kXmlHintEndAttributeValue    | End of attribute value     | `"` or `>`   |
| kXmlHintEndInnerText         | End of inner text          | `>`          |


## Future

* Support for unescaping inner text (such as `&nsbp;`)
* No dependencies on `memory.h` or `wtextrange.h`


## Examples

```cpp
XmlHint xml_skip_declaration(Xml *xml)
{
  int loop;

  loop = 1;
  while (loop != 0) {
    switch (xml_parse(xml)) {
    case kXmlHintEnded:
    case kXmlHintEndDeclaration:
      loop = 0;
      break;
    default:
      break;
    }
  }

  return xml->context;
}
```

For a complete example of parsing, see [Myst IV tools][1].


## Licence

ImXML was written by x1nixmzeng.

This code has been placed in the public domain


[1]:https://github.com/x1nixmzeng/mystiv-loc-tools/
