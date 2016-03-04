#ifndef DEF_XMLDATA
#define DEF_XMLDATA

#include "../utils/utils.hpp"

#include <string>
#include <vector>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMText.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>

class XMLData {
private:
	static XMLData* instance;
	XMLData() {};

public:
	XMLData(XMLData const&)			 = delete;
	void operator = (XMLData const&) = delete;

	static XMLData* getInstance();

private:
	int limbNbLength, limbSizeLength, limbTypeLength;
	int earNbLength;
	int eyeColorLength, eyeNbLength;
	int mouthWidthLength, teethNbLength, teethTypeLength;
	int nostrilNbLength;

	void parseDOMNode(xercesc::DOMNode* node);
	void parseDOMElement(xercesc::DOMElement* element);

public:
	int parseXML(std::string filePath);

	int LIMB_NB_LENGTH();
	int LIMB_SIZE_LENGTH();
	int LIMB_TYPE_LENGTH();

	int EAR_NB_LENGTH();

	int EYE_COLOR_LENGTH();
	int EYE_NB_LENGTH();

	int MOUTH_WIDTH_LENGTH();
	int TEETH_NB_LENGTH();
	int TEETH_TYPE_LENGTH();

	int NOSTRIL_NB_LENGTH();
};

#endif
