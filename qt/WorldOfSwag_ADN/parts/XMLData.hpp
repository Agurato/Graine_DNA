#ifndef DEF_XMLDATA
#define DEF_XMLDATA

#include "../utils/utils.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
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
	int hairTypeLength = -1;
	int limbNbLength, limbSizeLength, limbTypeLength = -1;
	int earNbLength;
	int eyeColorLength = 24, eyeNbLength;
	int mouthWidthTypeLength = -1, teethNbLength, teethTypeLength = -1;
	int nostrilNbLength;

	std::vector<std::string> hairTypes, limbTypes, mouthWidthTypes, teethTypes;

	void parseDOMNode(xercesc::DOMNode* node);
	void parseDOMElement(xercesc::DOMElement* element);

public:
	int parseXML(std::string filePath);

	int HAIR_TYPE_LENGTH();
	std::vector<std::string> getHairTypes();
	std::string getHairType(std::vector<bool> input);

	int LIMB_NB_LENGTH();
	int LIMB_SIZE_LENGTH();
	int LIMB_TYPE_LENGTH();
	std::vector<std::string> getLimbTypes();
	std::string getLimbType(std::vector<bool> input);

	int EAR_NB_LENGTH();

	int EYE_COLOR_LENGTH();
	int EYE_NB_LENGTH();

	int MOUTH_WIDTH_LENGTH();
	std::vector<std::string> getMouthWidthTypes();
	std::string getMouthWidthType(std::vector<bool> input);
	int TEETH_NB_LENGTH();
	int TEETH_TYPE_LENGTH();
	std::vector<std::string> getTeethTypes();
	std::string getTeethType(std::vector<bool> input);

	int NOSTRIL_NB_LENGTH();
};

#endif
