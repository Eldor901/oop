#include "pch.h"
#include "FuncToHtmlDecode.h"

struct htmlEntity
{
	char ch;
	string entity;
};

const htmlEntity QUOT = { '"', "&quot;" };
const htmlEntity APOS = { '\'', "&apos;" };
const htmlEntity LT = { '<', "&lt;" };
const htmlEntity GT = { '>', "&gt;" };
const htmlEntity AMP = { '&', "&amp;" };

string HtmlSearchEntity(const string &str, const string &searchStr, const char &replaceToCh)
{
	string changedStr;
	size_t index = 0;
	while (index < str.length())
	{
		size_t found = str.find(searchStr, index);
		if (found != string::npos)
		{
			changedStr.append(str, index, found - index);
			changedStr = changedStr + replaceToCh;
			index = found + searchStr.length();
		}
		else
		{
			changedStr.append(str, index);
			break;
		}
	}
	return changedStr;
}

string HtmlDecode(const string & stringHtml)
{
	string text;
	text = HtmlSearchEntity(stringHtml, QUOT.entity, QUOT.ch);
	text = HtmlSearchEntity(text, APOS.entity, APOS.ch);
	text = HtmlSearchEntity(text, LT.entity, LT.ch);
	text = HtmlSearchEntity(text, GT.entity, GT.ch);
	text = HtmlSearchEntity(text, AMP.entity, AMP.ch);
	return text;
}
