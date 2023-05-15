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
  ������
  ���Ƚ�����ı�������ʱ��Ĭ��ֻ������ѡ���½�һ���ļ����ߴ����е��ļ����������Ĳ�������Ĭ���ڽ��еĲ�����������ӣ�ɾ�����޸ġ�
  ���ܵ�ѡ��Ĭ����������������������
*/
class TextEditor {
public:
    void Show_Word();//��ʾ�ı�
    void Show_Menu();//��ʾ�˵���
    void New_Built();//�½�
    void Built_file();//�½�һ���ļ�
    void Open_file();//��һ���ļ�
    void Cin_word(string& line,vector< vector<string> > &word_temp);//���뺯��
    void  Scanf(string& line, vector<string> &Line);
    void Edit_word();//�༭
    void Save_file();//����
    void Add_word();//���
    void Change_word();//�޸�
    void Find_word();//����
    void Replace_word();//�滻
    void Exit_Menu();//�˳�
    void Delete_Menu();//ɾ��
    void Revoke_word();//����
    void Recove_word();//�ָ�
private:
    vector< vector< vector<string> > > Total_word;//������ų����ͻ��˲�����
    int count1 = 0, count2 =0;//����ֱ�����˶��ٴγ����ͻָ�����
    bool temp1= false, temp2= false;//�ж��Ƿ���й������ͻָ�����;
    vector< vector<string> > word;//�����ı���Ϣ��һ����ά��vector������
    string File_name;//���ļ���Ϊ�½�ʱ������ļ����������ļ�ʱĬ�ϱ�����Ը��ַ����������ļ���
};
void TextEditor::Show_Menu()
{
    cout << "--------------------------------------------�ı�������--------------------------------------------" << endl;
    cout << "(1)�½�  (2)����  (3)�༭ (4)���  (5)�޸�  (6)ɾ��  (7)����   (8)�滻  (9)����  (10)�ָ�  (11)�˳�" << endl;//Ĭ�ϸմ��ı�������ʱ��Ҫѡ���½�һ���ļ����ߴ������ļ���
}
void TextEditor::New_Built()
{
    cout << "�������ļ�(1)or�½�һ���ļ�(2)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        Open_file();
    }
    else {
        Built_file();
    }
    Total_word.clear();//ÿ�½�һ���ļ��������Total_word
    Total_word.push_back(word);
    count1 = 0;
    count2 = 0;
}
void TextEditor::Open_file()
{
    while (true) {
        cout << "����Ҫ���ļ�����" << endl;
        cin >> File_name;
        ifstream ifs;
        ifs.open(File_name, ios::in);//�Զ�����ʽ��
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
            cout << "������ļ�����������������" << endl;
        }
    }
}
void  TextEditor::Built_file()
{
    cout << "����Ҫ���ļ�����" << endl;
    cin >> File_name;
}
void TextEditor::Save_file()
{
    cout << "����Ϊ�µ��ļ�(1)or����ΪĬ���ļ�(2)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "����������Ҫ������ļ���" << endl;
        string file;//�����ļ���
        cin >> file;
        ofstream ofs;
        ifstream ifs;
        ifs.open(file, ios::in);//�Զ�����ʽ��
        if (ifs.is_open())
        {
            cout << "ͬ���ļ��Ѵ��ڣ��Ƿ�����滻��Y/N��" << endl;
            char ch;
            cin >> ch;
            if (ch == 'N')
            {
                cout << "�����±���" << endl;
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
        cout << "�ļ�����ɹ�" << endl;
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
        cout << "�ļ�����ɹ�" << endl;
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
        //Ӣ�ĵ�����һ�����ʴ棬�������յ����ַ���
        if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
        {
            s = s + line[i];
            if (i == line.size() - 1)
            {
                Line.push_back(s);
            }//��ֹ����������Ӣ�ĵ���
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
    cout << "��༭����ı�(�ԡ�#������Ϊһ�б�ʾ��β,Ĭ�ϼ����ı���β��)" << endl;
    cout << "�����ڵ�ǰ�ı���β��(1)or�����µ�һ��(2)" << endl;
    int choice;
    cin >> choice;
    char ch = getchar();
    if (choice == 1) {
        string line,s;
        getline(cin, line);
        vector<string> Line;
        Scanf(line, Line);
        int x = word.size() - 1;
        word[x].insert(word[x].end(), Line.begin(), Line.end());//������β��
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
    cout << "ȷ���Ƿ���(1 or 2)" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "�ļ��Ƿ񱣴�(1 or 2)" << endl;
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
        cout << "�˳�ʧ��" << endl;
    }
}
void TextEditor::Add_word()
{
    cout << "���ı��м�����µ��ı���1��or��ĳ���в����µ��ı���2��" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "��������ڼ����ı�֮�󣨿��Բ�������ı���" << endl;
        cin >> choice;
        string line;
        vector< vector<string> > word_temp;
        cout << "�����������ı�" << endl;
        char ch = getchar();
        while (getline(cin, line) && line != "#")
        {
            Cin_word(line,word_temp);
        }
        word.insert(word.begin() + choice, word_temp.begin(), word_temp.end());
    }
    else
    {
        cout << "�������ı�������кźͲ����λ�� ��Ĭ��ֻ�ܲ���һ���ı���" << endl;
        int x, y;
        cin >> x >> y;
        cout << "�����������ı�" << endl;
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
    cout << "ѡ���޸�һ����(1)or �޸�һ���е�ĳһ������(2)" << endl;
    int choice;
    cin >> choice;
    int x;
    string line;
    char ch;
    if (choice == 1)//�޸�һ����
    {
        cout << "������Ҫ�޸ĵ��кź��޸ĺ���е��ı���" << endl;
        cin >> x;
        ch = getchar();
        getline(cin, line);
        vector<string> Line;
        Scanf(line, Line);
        word[x - 1].swap(Line);
    }
    else
    {
        cout << "�������޸��ı����кź�Ҫ�޸ĵ��ı��Լ��޸ĺ���ı�" << endl;
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
    cout << "��ѡ��ɾ��ĳһ�У�1��orһ���е�ĳһ���ı���2��" << endl;
    int choice, x;
    string s1;
    cin >> choice;
    if (choice == 1)
    {
        cout << "������Ҫɾ�����к�" << endl;
        cin >> x;
        word.erase(word.begin() + x - 1);
    }
    else
    {
        cout << "�������ı����ڵ��к��Ը��ı�" << endl;
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
    cout << "������Ҫ���ҵĵ���" << endl;
    string s;
    cin >> s;
    tq.query(s);
}
void TextEditor::Replace_word()
{
    cout << "������Ҫ�滻�ĵ��ʺ��滻��ĵ���" << endl;
    string s1, s2;
    cin >> s1 >> s2;
    int temp = 0;//�������һ��û�еĵ����򲻸ı�
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
            cout << "�Ѿ�����ִ�г�������" << endl;
            return;
        }
    }
    if (count1==1)
    {
        cout << "�Ѿ�����ִ�г�������" << endl;
        return;
    }
    else  
    {
        count1--;
        word = Total_word[count1-1];
        cout << "�����ɹ�" << endl;
    }
    count2 = count1;
}
void TextEditor::Recove_word()
{
    if (count2 == Total_word.size())
    {
        cout << "�Ѿ�����ִ�лָ�����" << endl;
        return;
    }
    else
    {
        count2++;
        word = Total_word[count2-1];
        cout << "�ָ��ɹ�" << endl;
    }
    count1 = count2;
}
#endif
