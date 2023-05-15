#pragma once
#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include"Word_Find.h"
using namespace std;
/*
  设计理念：
  首先进入该文本编译器时，默认只有两个选择（新建一个文件或者打开已有的文件），后续的操作都是默认在进行的操作，比如添加，删除，修改。
  功能的选择默认以输入后面的数字来决定
*/
class TextEditor {
public:
    void Show_Word();//显示文本
    void Show_Menu();//显示菜单栏
    void New_Built();//新建
    void Built_file();//新建一个文件
    void Open_file();//打开一个文件
    void Cin_word(string& line,vector< vector<string> > &word_temp);//读入函数
    void  Scanf(string& line, vector<string> &Line);
    void Edit_word();//编辑
    void Save_file();//保存
    void Add_word();//添加
    void Change_word();//修改
    void Find_word();//查找
    void Replace_word();//替换
    void Exit_Menu();//退出
    void Delete_Menu();//删除
    void Revoke_word();//撤销
    void Recove_word();//恢复
private:
    vector< vector< vector<string> > > Total_word;//用来存放撤销和回退操作，
    int count1 = 0, count2 =0;//代表分别进行了多少次撤销和恢复操纵
    bool temp1= false, temp2= false;//判断是否进行过撤销和恢复操作;
    vector< vector<string> > word;//保存文本信息，一个二维的vector容器；
    string File_name;//此文件名为新建时输入的文件名，保存文件时默认保存成以该字符串命名的文件；
};
void TextEditor::Show_Menu()
{
    cout << "--------------------------------------------文本编译器--------------------------------------------" << endl;
    cout << "(1)新建  (2)保存  (3)编辑 (4)添加  (5)修改  (6)删除  (7)查找   (8)替换  (9)撤销  (10)恢复  (11)退出" << endl;//默认刚打开文本编译器时，要选择新建一个文件或者打开已有文件；
}
void TextEditor::New_Built()
{
    cout << "打开已有文件(1)or新建一个文件(2)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        Open_file();
    }
    else {
        Built_file();
    }
    Total_word.clear();//每新建一个文件，则清空Total_word
    Total_word.push_back(word);
    count1 = 0;
    count2 = 0;
}
void TextEditor::Open_file()
{
    while (true) {
        cout << "输入要打开文件的名" << endl;
        cin >> File_name;
        ifstream ifs;
        ifs.open(File_name, ios::in);//以读的形式打开
        if (ifs.is_open())
        {
            string line;
            while (getline(ifs, line))
            {
                Cin_word(line,word);
            }
            break;
        }
        else {
            cout << "输入的文件名有误，请重新输入" << endl;
        }
    }
}
void  TextEditor::Built_file()
{
    cout << "输入要打开文件的名" << endl;
    cin >> File_name;
}
void TextEditor::Save_file()
{
    cout << "保存为新的文件(1)or保存为默认文件(2)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "请输入您将要保存的文件名" << endl;
        string file;//输入文件名
        cin >> file;
        ofstream ofs;
        ifstream ifs;
        ifs.open(file, ios::in);//以读的形式打开
        if (ifs.is_open())
        {
            cout << "同名文件已存在，是否进行替换（Y/N）" << endl;
            char ch;
            cin >> ch;
            if (ch == 'N')
            {
                cout << "请重新保存" << endl;
                return;
            }
        }
        ofs.open(file, ios::trunc);
        for (auto a : word)
        {
            for (auto b : a)
            {
                ofs << b << " ";
            }
            ofs << endl;
        }
        cout << "文件保存成功" << endl;
    }
    else {
        ofstream ofs;
        ofs.open(File_name,ios::trunc);
        for (auto a : word)
        {
            for (auto b : a)
            {
                ofs << b << " ";
            }
            ofs << endl;
        }
        cout << "文件保存成功" << endl;
    }
}
void TextEditor::Cin_word(string& line, vector< vector<string> > &word_temp)
{
    vector<string> Line;
    Scanf(line, Line);
    word_temp.push_back(Line);
}
void TextEditor::Scanf(string& line,vector<string>& Line)
{
    string s;
    for (int i = 0; i < line.size(); i++) {
        //英文单词以一整个词存，其他则按照单个字符存
        if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
        {
            s = s + line[i];
            if (i == line.size() - 1)
            {
                Line.push_back(s);
            }//防止最后输入的是英文单词
        }
        else
        {
            if (s != "")
            {
                Line.push_back(s);
            }
            Line.push_back(string(1, line[i]));
            s = "";
        }
    }
}
void TextEditor::Edit_word()
{
    cout << "请编辑你的文本(以“#”单独为一行表示结尾,默认加在文本的尾部)" << endl;
    cout << "连接在当前文本的尾部(1)or另起新的一行(2)" << endl;
    int choice;
    cin >> choice;
    char ch = getchar();
    if (choice == 1) {
        string line,s;
        getline(cin, line);
        vector<string> Line;
        Scanf(line, Line);
        int x = word.size() - 1;
        word[x].insert(word[x].end(), Line.begin(), Line.end());//插入在尾部
        while (getline(cin, line) && line != "#")
        {
            Cin_word(line,word);
        }
    }
    else
    {
       string line;
       while (getline(cin, line) && line != "#")
       {
        Cin_word(line,word);
       }
    }
    Total_word.push_back(word);
}
void TextEditor::Show_Word()
{
    for (auto a : word)
    {
        for (auto b : a)
        {
            cout << b;
        }
        cout << endl;
    }
}
void TextEditor::Exit_Menu()
{
    cout << "确定是否退(1 or 2)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "文件是否保存(1 or 2)" << endl;
        cin >> choice;
        if (choice == 1)
        {
            exit(0);
        }
        else
        {
            Save_file();
        }
    }
    else
    {
        cout << "退出失败" << endl;
    }
}
void TextEditor::Add_word()
{
    cout << "在文本中间插入新的文本（1）or在某行中插入新的文本（2）" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "输入插入在几行文本之后（可以插入多行文本）" << endl;
        cin >> choice;
        string line;
        vector< vector<string> > word_temp;
        cout << "请输入插入的文本" << endl;
        char ch = getchar();
        while (getline(cin, line) && line != "#")
        {
            Cin_word(line,word_temp);
        }
        word.insert(word.begin() + choice, word_temp.begin(), word_temp.end());
    }
    else
    {
        cout << "请输入文本插入的行号和插入的位置 （默认只能插入一行文本）" << endl;
        int x, y;
        cin >> x >> y;
        cout << "请输入插入的文本" << endl;
        char ch = getchar();
        string line;
        vector<string> Line;
        getline(cin, line);
        Scanf(line, Line);
        word[x - 1].insert(word[x - 1].begin() + y, Line.begin(), Line.end());
    }
    Total_word.push_back(word);
}
void TextEditor::Change_word()
{
    cout << "选择修改一整行(1)or 修改一行中的某一个单词(2)" << endl;
    int choice;
    cin >> choice;
    int x;
    string line;
    char ch;
    if (choice == 1)//修改一整行
    {
        cout << "请输入要修改的行号和修改后该行的文本：" << endl;
        cin >> x;
        ch = getchar();
        getline(cin, line);
        vector<string> Line;
        Scanf(line, Line);
        word[x - 1].swap(Line);
    }
    else
    {
        cout << "请输入修改文本的行号和要修改的文本以及修改后的文本" << endl;
        string s1, s2;
        cin >> x >> s1 >> s2;
        int count = 0;
        for (auto a : word[x - 1])
        {
            if (a == s1)
            {
                break;
            }
            count++;
        }
        word[x - 1][count] = s2;
    }
    Total_word.push_back(word);
}
void TextEditor::Delete_Menu()
{
    cout << "请选择删除某一行（1）or一行中的某一个文本（2）" << endl;
    int choice, x;
    string s1;
    cin >> choice;
    if (choice == 1)
    {
        cout << "请输入要删除的行号" << endl;
        cin >> x;
        word.erase(word.begin() + x - 1);
    }
    else
    {
        cout << "请输入文本所在的行号以该文本" << endl;
        cin >> x >> s1;
        int count = 1;
        for (auto a : word[x - 1])
        {
            if (a == s1)
            {
               word[x - 1].erase(word[x - 1].begin()+count-1);
            }
            count++;
        }
    }
    Total_word.push_back(word);
}
void TextEditor::Find_word()
{
    TextQuery tq(word);
    cout << "请输入要查找的单词" << endl;
    string s;
    cin >> s;
    tq.query(s);
}
void TextEditor::Replace_word()
{
    cout << "请输入要替换的单词和替换后的单词" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    int temp = 0;//如果输入一个没有的单词则不改变
    for (auto& a : word)
    {
        for (auto& b : a)
        {
            if (b == s1)
            {
                b = s2;
            }
        }
    }
}
void TextEditor::Revoke_word()
{
    if (temp1== false)
    {
        count1 = Total_word.size();
        if (count1==1)
        {
            cout << "已经不能执行撤销操作" << endl;
            return;
        }
    }
    if (count1==1)
    {
        cout << "已经不能执行撤销操作" << endl;
        return;
    }
    else  
    {
        count1--;
        word = Total_word[count1-1];
        cout << "撤销成功" << endl;
    }
    count2 = count1;
}
void TextEditor::Recove_word()
{
    if (count2 == Total_word.size())
    {
        cout << "已经不能执行恢复操作" << endl;
        return;
    }
    else
    {
        count2++;
        word = Total_word[count2-1];
        cout << "恢复成功" << endl;
    }
    count1 = count2;
}
#endif
