#include<iostream>
#include"text_editor.h"
using namespace std;
int main()
{
	TextEditor textEditor;
	while (true)
	{
		textEditor.Show_Menu();
		textEditor.Show_Word();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			textEditor.New_Built();
			break;
		case 2:
			textEditor.Save_file();
			break;
		case 3:
			textEditor.Edit_word();
			break;
		case 4:
			textEditor.Add_word();
			break;
		case 5:
			textEditor.Change_word();
			break;
		case 6:
			textEditor.Delete_Menu();
			break;
		case 7:
			textEditor.Find_word();
			break;
		case 8:
			textEditor.Replace_word();
			break;
		case 9:
			textEditor.Revoke_word();
			break;
		case 10:
			textEditor.Recove_word();
			break;
		case 11:
			textEditor.Exit_Menu();
			break;
		default:
			cout << "---------���ı�������û�иù��ܣ�����������ѡ��:" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}