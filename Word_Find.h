#pragma once
#ifndef WORD_FIND_H
#define WORD_FIND_H
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
using line_no = vector<string>::size_type;
class TextQuery {
public:
	TextQuery(vector< vector<string> >&);
	map<string, shared_ptr<set<line_no> > > wm;
	void query(string& s);
};
TextQuery::TextQuery(vector< vector<string> >& h)
{
	int n = 1;
	for (auto a : h)
	{
		for (auto b : a)
		{
			auto& lines = wm[b];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
		n++;
	}
}
void TextQuery::query(string& s)
{
	auto iter = wm.find(s);
	if (iter != wm.end())
	{
		cout << "�ı�" + s + "�������г��ֹ�" << endl;
		for (auto s : *wm[s])
		{
			cout << s << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "�ı�" + s + "û�г��ֹ�" << endl;
	}
}
#endif WORD_FIND_h

